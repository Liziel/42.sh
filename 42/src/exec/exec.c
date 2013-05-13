/*
** exec.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 16:04:18 2013 vincent colliot
** Last update Mon May 13 00:37:32 2013 vincent colliot
*/

static BOOL	set_redir(t_redir *r, FD w[3])
{
  if (calque_redir(r, w) == FALSE)
    return (FALSE);
  dup2(W[W_IN], W_IN);
  dup2(W[W_OUT], W_OUT);
  dup2(W[W_ERR], W_ERR);
  return (TRUE);
}

BOOL		exec_cmd(t_cmd *cmd, t_info *st, BOOL son, FD w[3])
{
  if (set_redir() == FALSE)
    return (FALSE);
}
