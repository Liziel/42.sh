/*
** redir_d_left.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 13 00:38:40 2013 vincent colliot
** Last update Tue May 21 20:38:50 2013 vincent colliot
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "orga.h"
#include "exec.h"
#include "edit_line.h"
#include "string.h"
#include "xlib.h"

static t_words	*get_alls(FD rw, t_options termcaps, t_words *prev, char *m)
{
  char		*line;
  t_words	*link;

  if ((line = usr_cmd(rw, NULL, termcaps)) == NULL)
    {
      my_putstr("(sh):error while matching for ", rw);
      my_putstr(m, rw);
      my_putstr("\n", rw);
      return (prev);
    }
  if (MATCH(m, line))
    return (prev);
  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (prev);
  link->word = line;
  link->next = NULL;
  if (prev)
    prev->next = link;
  get_alls(rw, termcaps, link, m);
  if (!prev)
    close(rw);
  return (link);
}

static BOOL	put_lines(t_words *l, FD wr)
{
  if (!l)
    return (FALSE);
  my_putstr(l->word, wr);
  my_putstr("\n", wr);
  put_lines(l->next, wr);
  free(l->word);
  free(l);
  return (FALSE);
}

BOOL	rdleft(t_redir *r, FD w[3], t_info *info)
{
  t_words	*l;
  FD	p[2];

  if ((p[0] = open("/dev/tty", O_RDWR)) == -1)
    {
      print_err("(sh): can't open tty\n");
      return (TRUE);
    }
  l = get_alls(p[0], info->termcaps, NULL, r->file);
  close(p[0]);
  if (pipe(p) == -1)
    perror("pipes::");
  put_lines(l, p[W_OUT]);
  if (w[r->in] >= 0)
    close(w[r->in]);
  close(p[W_OUT]);
  w[r->in] = p[W_IN];
  return (TRUE);
}
