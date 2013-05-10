/*
** comment.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 14:50:23 2013 vincent colliot
** Last update Fri May 10 14:56:48 2013 vincent colliot
*/

#include "get.h"
#include "xmalloc.h"
#include "bool.h"

static BOOL nullify_next(t_get *w)
{
  t_get	*next;

  if (!w)
    return (FALSE);
  next = w->next;
  free(w->word);
  free(w);
  return (nullify_next(next));
}

BOOL	comment(t_get *w)
{
  char *s;

  if (!w)
    return (TRUE);
  if ((w->word)[0] != '"')
    comment(w->next);
  if ((s = my_strndup(w->word + 1, my_strilen(w->word + 1, '"'))) == NULL)
    {
      nullify_next(w->next);
      free(w);
      return (FALSE);
    }
  free(w->word);
  w->word = s;
  if (comment(w->next) == FALSE)
    {
      free(w->word);
      free(w);
      return (FALSE);
    }
  return (TRUE);
}
