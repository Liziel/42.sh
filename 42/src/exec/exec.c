/*
** exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 16:04:18 2013 vincent colliot
** Last update Mon May 13 14:39:16 2013 vincent colliot
*/

static BOOL	set_redir(t_redir *r, FD w[3], t_info *info)
{
  if (calque_redir(r, w, info) == FALSE)
    return (FALSE);
  dup2(W[W_IN], W_IN);
  dup2(W[W_OUT], W_OUT);
  dup2(W[W_ERR], W_ERR);
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
  if (set_redir(cmd->r, w, info) == FALSE)
    return (FALSE);
  if (!exec_built_in(cmd, info))
    info->st = exec_form(cmd, &sys_fail);
  if (sys_fail == TRUE)
    return (FALSE);
  while (waitpid(-1, &dleft, 0) != -1);
  return (TRUE);
}
