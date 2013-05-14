/*
** pré-exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 14:58:16 2013 vincent colliot
** Last update Tue May 14 01:42:03 2013 vincent colliot
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "orga.h"
#include "exec.h"
#include "xlib.h"

static void	init_pipe(FD w[2], FD pi[3], FD h)
{
  pi[h] = w[h];
  close(w[!h]);
}

/*
**bon elle est pas tellement a la norme...mais ce sera vrai sous peu FAUX
*/
static BOOL	exec_pipes(t_pipes *p, t_info *info, BOOL son, FD pi[3])
{
  STATUS	status_quo;
  pid_t		pid;
  FD		w[2];

  pid = -1;
  if (p->next)
    {
      if ((pid = xfork()) < 0)
	return (FALSE);
      if (pipe(w) == -1)
	return (FALSE);
    }
  if (!pid)
    {
      init_pipe(w, pi, W_IN);
      exec_pipes(p->next, info, TRUE, pi);
      return (FALSE);
    }
  if (p->next)
    init_pipe(w, pi, W_OUT);
  if (exec_cmd(p->cmd, info, son, pi) == FALSE)
    return (FALSE);
  if (pid < 0)
    return (TRUE);
  waitpid(pid, &status_quo, 0);
  if (WEXITSTATUS(status_quo) == EXIT_FAILURE)
    info->st = EXIT_FAILURE;
  return (TRUE);
}

static void to_fd(FD w[3])
{
  w[W_IN] = dup(W_IN);
  w[W_OUT] = dup(W_OUT);
  w[W_ERR] = dup(W_ERR);
}

static void fd_to(FD w[3])
{
  dup2(w[W_IN], W_IN);
  dup2(w[W_OUT], W_OUT);
  dup2(w[W_ERR], W_OUT);
}

static BOOL	and_or(t_exec *e, t_info *info)
{
  FD	p[3];
  FD	w[3];

  if (!e)
    return (TRUE);
  to_fd(w);
  p[W_IN] = W_IN;
  p[W_OUT] = W_OUT;
  p[W_ERR] = W_ERR;
  if (exec_pipes(e->pipes, info, FALSE, p) == FALSE)
    return (FALSE);
  fd_to(w);
  if (e->type == OR && info->st == EXIT_FAILURE)
    return (and_or(e->next, info));
  if (e->type == AND && info->st == EXIT_SUCCESS)
    return (and_or(e->next, info));
  return (TRUE);
}

BOOL	pre_exec(t_jobs *j, t_info *info)
{
  t_jobs *next;

  if (!j)
    return (TRUE);
  if (and_or(j->exec, info) == FALSE)
    return (FALSE);
  next = j->next;
  nullify_jobs(j, 0);
  return (pre_exec(next, info));
}
