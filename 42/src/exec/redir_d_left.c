/*
** redir_d_left.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 13 00:38:40 2013 vincent colliot
** Last update Mon May 13 02:27:59 2013 vincent colliot
*/

BOOL	rdleft(t_redir *r, FD w[3])
{
  t_words	*lines;
  pid_t	pid;
  FD	p[2];

  if ((p[0] = open("/dev/tty4", O_RDONLY)) == -1)
    {
      put_err("(sh): can't open tty4\n");
      return (TRUE);
    }
  //lines = get_alls(p[0]);
  close(p[0]);
  pipes(p);
  if ((pid = xfork()) == -1)
    return (FALSE);
  if (!pid)
    {
      close(p[W_IN]);
      return (put_lines(lines, w[P_OUT]));
    }
  close(p[W_OUT]);
  w[r->in] = p[W_IN];
  nullify_cmd_words(lines);
  return (TRUE);
}
