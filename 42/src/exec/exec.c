/*
** exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 16:04:18 2013 vincent colliot
** Last update Wed May 15 01:44:41 2013 vincent colliot
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "orga.h"
#include "fd.h"
#include "bool.h"
#include "exec.h"
#include "father.h"

static BOOL	set_redir(t_redir *r, FD w[3], t_info *info, FLAG son)
{
  FD		pi[3];
  FD		in;

  in = 0;
  while (in < 3)
    pi[in++] = -1;
  if (r)
    if (calque_redir(r, pi, w, info) == FALSE)
      return (FALSE);
  in = 0;
  while (in < 3)
    {
      if (pi[in] >= 0)
	dup2(pi[in], in);
      if ((in == W_IN && (son & SON)) || (in == W_OUT && (son & FATHER)))
	dup2(w[in], in);
      in++;
    }
  return (TRUE);
}

static BOOL	exec_built_in(t_cmd *cmd, t_info *info)
{
  return (FALSE);
  //sera changé losque les builts-in seront finies
}

BOOL		exec_cmd(t_cmd *cmd, t_info *info, FLAG son, FD w[3])
{
  BOOL		sys_fail;
  STATUS	dleft;

  sys_fail = FALSE;
  if (set_redir(cmd->redir, w, info, son) == FALSE)
    return (FALSE);
  if (cmd->type == WORDS)
    if (!exec_built_in(cmd, info))
      info->st = exec_form(cmd->params, &sys_fail, son);
  if (cmd->type == PARENTS)
    pre_exec(cmd->parents, info);
  cmd->parents = NULL;
  if (son & FATHER)
    close(w[W_OUT]);
  if ((son & SON) || w[W_IN] != W_IN)
    close(W_IN);
  if ((son & FATHER) || w[W_OUT] != W_OUT)
    close(W_OUT);
  if (w[W_ERR] != W_ERR)
    close(W_ERR);
  if (sys_fail == TRUE)
    return (FALSE);
  return ((son & SON) == FALSE);
}
