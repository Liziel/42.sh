/*
** pré-exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 14:58:16 2013 vincent colliot
** Last update Sun May 26 04:00:48 2013 vincent colliot
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "orga.h"
#include "exec.h"
#include "xlib.h"
#include "father.h"

static void	init_pipe(FD w[2], FD pi[3], FD h)
{
  close(pi[h]);
  pi[h] = w[h];
  close(w[!h]);
}

static void	my_wait(pid_t son, STATUS *st)
{
  STATUS stat;
  pid_t	pid;

  while ((pid = waitpid(-1, &stat, WNOHANG)) >= 0)
    {
      if (pid == son)
  	*st = stat;
    }
}

static BOOL	get_status(t_info *info, STATUS st)
{
  if (info->st != EXIT_FAILURE)
    info->st = (0 != (WEXITSTATUS(st)));
  info->value = WEXITSTATUS(st);
  return (TRUE);
}

static BOOL	exec_pipes(t_pipes *p, t_info *info, FLAG son, FD pi[3])
{
  STATUS	status_quo;
  pid_t		pid;
  FD		w[2];

  if (!(pid = -(!((unsigned long)(p->next != NULL)))))
    {
      if (pipe(w) == -1)
	return (FALSE);
      if ((pid = xfork()) < 0)
	return (FALSE);
    }
  if (!pid)
    {
      init_pipe(w, pi, W_IN);
      exec_pipes(p->next, info, SON, pi);
      return (FALSE);
    }
  if (p->next)
    init_pipe(w, pi, W_OUT);
  if (exec_cmd(p->cmd, info, son | (FATHER * (pid > 0)), pi) == FALSE)
    return (FALSE);
  my_wait(pid, &status_quo);
  if (pid < 0)
    return (TRUE);
  return (get_status(info, status_quo));
}

static void to_fd(FD w[3], BOOL in)
{
  if (in)
    return ;
  w[W_IN] = dup(W_IN);
  w[W_OUT] = dup(W_OUT);
  w[W_ERR] = dup(W_ERR);
}

static void fd_to(FD w[3], BOOL in)
{
  if (in)
    return ;
  dup2(w[W_OUT], W_OUT);
  close(w[W_OUT]);
  dup2(w[W_IN], W_IN);
  close(w[W_IN]);
  dup2(w[W_ERR], W_OUT);
  close(w[W_ERR]);
}

static t_exec	*two(t_exec *t)
{
  if (!t->next)
    return (NULL);
  else if (!t->next->next)
    return (NULL);
  return (t->next->next);
}

static BOOL	and_or(t_exec *e, t_info *info, BOOL in)
{
  FD	p[3];
  FD	w[3];

  if (!e)
    return (TRUE);
  to_fd(w, in);
  p[W_IN] = W_IN;
  p[W_OUT] = W_OUT;
  p[W_ERR] = W_ERR;
  if (exec_pipes(e->pipes, info, 0, p) == FALSE)
    {
      while (waitpid(-1, NULL, WNOHANG) >= 0);
      return (FALSE);
    }
  fd_to(w, in);
  if (e->type == OR && info->st == EXIT_FAILURE)
    return (and_or(e->next, info, in));
  else if (e->type == OR && info->st == EXIT_SUCCESS)
    return (and_or(two(e), info, in));
  if (e->type == AND && info->st == EXIT_SUCCESS)
    return (and_or(e->next, info, in));
  else if (e->type == AND && info->st == EXIT_FAILURE)
    return (and_or(two(e), info, in));
  return (TRUE);
}

BOOL	pre_exec(t_jobs *j, t_info *info, BOOL in)
{
  t_jobs *next;

  if (!j)
    return (TRUE);
  if (and_or(j->exec, info, in) == FALSE)
    return (FALSE);
  next = j->next;
  nullify_jobs(j, 0);
  return (pre_exec(next, info, in));
}
