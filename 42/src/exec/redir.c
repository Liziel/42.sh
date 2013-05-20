/*
** redir.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun May 12 22:15:18 2013 vincent colliot
** Last update Mon May 20 20:09:01 2013 vincent colliot
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "orga.h"
#include "exec.h"

void	rleft(t_redir *r, FD w[3])
{
  FD	in;

  in = r->in;
  close(w[in]);
  w[in] = open(r->file, O_RDONLY);
}

void	rright(t_redir *r, FD w[3], FD l[3])
{
  FD	in;

  in = r->in;
  if (w[in] != -1)
    close(w[in]);
  if (r->type != ON_CANAL)
    w[in] = open(r->file, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IROTH);
  if (r->type == ON_CANAL)
    {
      close(l[in]);
      w[in] = dup(l[r->out]);
    }
}

static void	rdright(t_redir *r, FD w[3])
{
  FD	in;

  in = r->in;
  close(w[in]);
  if ((w[in] = open(r->file, O_WRONLY)) == -1)
    w[in] = open(r->file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH);
}

BOOL	calque_redir(t_redir *r, FD w[3], FD l[3], t_info *info)
{
  if (!r)
    return (TRUE);
  if (r->redir == LEFT)
    rleft(r, w);
  else if (r->redir == DLEFT)
    {
      if (rdleft(r, w, info) == FALSE)
	return (FALSE);
    }
  else if (r->redir == RIGHT)
    rright(r, w, l);
  else if (r->redir == DRIGHT)
    rdright(r, w);
  return (calque_redir(r->next, w, l, info));
}
