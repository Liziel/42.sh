/*
** cmd_part.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 18:33:37 2013 vincent colliot
** Last update Wed May  8 23:53:59 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"
#include "error.h"

static t_words	*nullify_link(t_words *link)
{
  t_words *next;

  if (!link)
    return (NULL);
  next = link->next;
  free(link);
  return (nullify_link(next));
}

static t_words	*list_cmd(t_get *word, t_get **words, t_words *prev, char **bad_sintax)
{
  t_words *link;
  t_words *last;

  if (!words)
    return (prev);
  if ((IN('>', word->word) || IN('<', word->word)) && !IN(word->word[0], "'\"")
      && !word->inter)
    return (prev);
  if (!prev)
    if ((link = interpret_cmd(word, words, bad_sintax, &last)) == NULL)
      return (NULL);
  if (prev)
    if ((link = interpret_params(word, words, bad_sintax, &last)) == NULL)
      return (NULL);
  if (list_cmd(*words, words, last, bad_sintax) == NULL)
    {
      last->next = NULL;
      return (nullify_link(link));
    }
  return (link);
}

static BOOL	check_sintax(char **bad_sintax, BOOL null)
{
  if (null)
    *bad_sintax = my_strdup(UNMATCHED_PARENTS);
  return (FALSE);
}

static BOOL	parents(t_get *word, t_get **words, t_cmd *link, char **bad_sintax)
{
  BOOL		no_word;
  t_get	*organize;

  if (lvl_parents(words, bad_sintax) == FALSE)
    return (FALSE);
  if ((organize = word->next))
    word->next->prev = NULL;
  free(word);
  if ((word = *words) == NULL)
    return (FALSE);
  if (word->prev)
    if(word->prev->prev)
      word->prev->prev->next = NULL;
  if ((link->parents = orga(organize, bad_sintax, &no_word)) == NULL)
    return (check_sintax(bad_sintax, no_word));
  return (TRUE);
}

BOOL	cmd_part(t_get *word, t_get **words, t_cmd *link, char **bad_sintax)
{
  link->type = PARENTS;
  if (MATCH(word->word, "("))
    return (parents(word, words, link, bad_sintax));
  link->type = WORDS;
  if ((link->params = list_cmd(word, words, NULL, bad_sintax)) == NULL)
    if (!(IN('>', word->word) || IN('<', word->word)))
      return (FALSE);
  return (TRUE);
}
