/*
** redir_d_left.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 13 00:38:40 2013 vincent colliot
** Last update Sun May 26 05:59:58 2013 vincent colliot
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
#include "env.h"

static t_words	*get_alls(FD rw, t_words *prev, char *m)
{
  struct  s_options termcaps;
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
  get_alls(rw, link, m);
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

static void	set_rd_prompt(char **pt, int lap)
{
  if (lap == 0)
    {
      *pt = my_strdup(get_env("PS1"));
      set_env("PS1", "> ");
      return ;
    }
  set_env("PS1", *pt);
  free(*pt);
}

BOOL	rdleft(t_redir *r, FD w[3], FD pi[3])
{
  char		*pt;
  t_words	*l;
  FD		p[2];

  (void)pi;
  set_rd_prompt(&pt, 0);
  p[0] = open("/dev/tty", O_RDWR);
  l = get_alls(p[W_IN], NULL, r->file);
  close(p[0]);
  set_rd_prompt(&pt, 1);
  if (pipe(p) == -1)
    fprintf(stderr, "pipes error\n");
  put_lines(l, p[W_OUT]);
  if (w[r->in] >= 0)
    close(w[r->in]);
  close(p[W_OUT]);
  w[r->in] = p[W_IN];
  return (TRUE);
}
