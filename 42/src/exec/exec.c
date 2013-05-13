/*
** exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 16:04:18 2013 vincent colliot
** Last update Tue May 14 00:52:45 2013 vincent colliot
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "orga.h"
#include "fd.h"
#include "bool.h"
#include "exec.h"

static BOOL	set_redir(t_redir *r, FD w[3], t_info *info)
{
  if (calque_redir(r, w, info) == FALSE)
    return (FALSE);
  dup2(w[W_IN], W_IN);
  dup2(w[W_OUT], W_OUT);
  dup2(w[W_ERR], W_ERR);
  return (TRUE);
}

static BOOL	exec_built_in(t_cmd *cmd, t_info *info)
{
  return (FALSE);
  //sera changé losque les builts-in seront finies
}

BOOL		exec_cmd(t_cmd *cmd, t_info *info, BOOL son, FD w[3])
{
  BOOL		sys_fail;
  STATUS	dleft;

  sys_fail = FALSE;
  if (set_redir(cmd->redir, w, info) == FALSE)
    return (FALSE);
  if (cmd->type == WORDS)
    if (!exec_built_in(cmd, info))
      info->st = exec_form(cmd->params, &sys_fail);
  if (cmd->type == PARENTS)
    pre_exec(cmd->parents, info);
  if (sys_fail == TRUE)
    return (FALSE);
  while (waitpid(-1, &dleft, 0) != -1);
  return (son == FALSE);
}
