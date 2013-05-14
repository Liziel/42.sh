/*
** exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 16:04:18 2013 vincent colliot
** Last update Tue May 14 22:01:09 2013 vincent colliot
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "orga.h"
#include "fd.h"
#include "bool.h"
#include "exec.h"
#include "father.h"

static BOOL	set_redir(t_redir *r, FD w[3], t_info *info)
{
  if (r)
    if (calque_redir(r, w, info) == FALSE)
      return (FALSE);
  dup2(w[W_ERR], W_ERR);
  dup2(w[W_OUT], W_OUT);
  dup2(w[W_IN], W_IN);
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
  if (set_redir(cmd->redir, w, info) == FALSE)
    return (FALSE);
  if (cmd->type == WORDS)
    if (!exec_built_in(cmd, info))
      info->st = exec_form(cmd->params, &sys_fail, son);
  if (cmd->type == PARENTS)
    pre_exec(cmd->parents, info);
  cmd->parents = NULL;
  if (son & FATHER)
    close(w[W_OUT]);
  close(W_OUT);
  if (sys_fail == TRUE)
    return (FALSE);
  return ((son & SON) == FALSE);
}
