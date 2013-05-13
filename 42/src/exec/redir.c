/*
** redir.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun May 12 22:15:18 2013 vincent colliot
** Last update Mon May 13 13:14:21 2013 vincent colliot
*/

void	rleft(t_redir *w, FD w[3])
{
  FD	in;

  in = w->in;
  close(w[in]);
  w[in] = open(w->file, O_RDONLY);
}

void	rright(t_redir *w, FD w[3])
{
  FD	in;

  in = w->in;
  close(w[in]);
  if (w->type == ON_CANAL)
    w[in] = open(w->file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR
            | S_IRGRP | S_IROTH);
  else
    w[in] = dup(w[w->out]);
}

static void	rdright(t_redir *w, FD w[3])
{
  FD	in;

  in = w->in;
  close(w[in]);
  if ((w[in] = open(w->file, O_WRONLY)) == -1)
    w[in] = open(w->file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR
		 | S_IRGRP | S_IROTH);
}

BOOL	calque_redir(t_redir *r, FD w[3], t_info *info)
{
  if (!r)
    return ;
  if (r->redir == LEFT)
    rleft(r, w);
  else if (r->redir == DLEFT)
    {
      if (rdleft(r, w, info) == FALSE)
	return (FALSE);
    }
  else if (r->redir == RIGHT)
    rright(r, w);
  else if (r->redir == DRIGHT)
    rdright(r, w);
  return (calque_redir(r->next, w));
}
