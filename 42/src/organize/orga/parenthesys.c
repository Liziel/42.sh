/*
** parenthesys.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 01:01:26 2013 vincent colliot
** Last update Fri May 10 13:08:09 2013 vincent colliot
*/

#include "get.h"
#include "bool.h"
#include "string.h"
#include "error.h"

BOOL	lvl_parents(t_get **words, char **bad_sintax)
{
  t_get *link;
  int	plevel;
  int   blevel;

  plevel = 0;
  if ((!(blevel = MATCH("(", (*words)->word))
       && !(plevel = MATCH("`", (*words)->word))) || (*words)->inter)
    return (TRUE);
  link = (*words)->next;
  while (link && (plevel || blevel))
    {
      blevel = blevel + !(link->inter) * (MATCH("(", (link)->word)
					  - MATCH(")", (link)->word));
      if (MATCH("`", (link)->word))
	plevel = !plevel;
      link = link->next;
    }
  if (plevel)
    *bad_sintax = my_strdup(UNMATCHED_PARENTS);
  if (blevel)
    *bad_sintax = my_strdup(UNMATCHED_BACKMACHIN);
  if (plevel || blevel)
    return (FALSE);
  *words = link;
  return (TRUE);
}

BOOL	match_parents(t_get **words, char **bad_sintax)
{
  t_get *link;
  int	plevel;
  int   blevel;

  plevel = 0;
  if (!(blevel = MATCH("(", (*words)->word))
      && !(plevel = MATCH("`", (*words)->word)))
    return (TRUE);
  link = (*words)->next;
  while (link && (plevel || blevel))
    {
      blevel = blevel + MATCH("(", (link)->word) - MATCH(")", (link)->word);
      if (MATCH("`", (link)->word))
	plevel = !plevel;
      *words = link;
      link = link->next;
    }
  if (plevel)
    *bad_sintax = my_strdup(UNMATCHED_PARENTS);
  if (blevel)
    *bad_sintax = my_strdup(UNMATCHED_BACKMACHIN);
  if (plevel || blevel)
    return (FALSE);
  if (link)
    *words = link;
  return (TRUE);
}
