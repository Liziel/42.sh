/*
** redir_d_left.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 13 00:38:40 2013 vincent colliot
** Last update Mon May 13 14:13:58 2013 vincent colliot
*/

t_words	*get_alls(FD rw, t_options termcaps, t_words *prev, char *m)
{
  char		*line;
  t_words	*link;

  if ((line = edit_line(rw, termcaps)) == NULL)
    {
      my_putstr("(sh):error while matching for", rw);
      my_putstr(m, rw);
      my_putstr("\n", rw);
      return (prev);
    }
  if (MATCH(m, line))
    return (prev);
  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (prev);
  link->word = line;
  if (prev)
    prev->next = link;
  get_alls(rw, termcaps, t_words *link, m);
  if (!prev)
    close(rw);
  return (link);
}

static BOOL	put_lines(t_words *lines, FD wr)
{
  if (!lines)
    return (FALSE);
  my_putstr(lines, wr);
  put_lines(lines, wr);
  free(lines);
  return (FALSE);
}

BOOL	rdleft(t_redir *r, FD w[3], t_info *info)
{
  t_words	*lines;
  pid_t	pid;
  FD	p[2];

  if ((p[0] = open("/dev/tty", O_RDWR)) == -1)
    {
      put_err("(sh): can't open tty\n");
      return (TRUE);
    }
  lines = get_alls(p[0], info->termcaps, NULL, r->file);
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
