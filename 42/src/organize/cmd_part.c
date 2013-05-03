/*
** cmd_part.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 18:33:37 2013 vincent colliot
** Last update Fri May  3 19:11:32 2013 vincent colliot
*/

#include "lexec.h"
#include "bool.h"

static t_words	*nullify_link(t_words *link, t_words *prev)
{
  t_words *next;

  if (!link)
    return (NULL);
  if (link->prev && !prev)
    link->prev->next = NULL;
  next = link->next;
  free(link);
  return (nullify_link(next, link));
}

static t_words	*list_cmd(t_get *word, t_get **words, t_words *prev, char **bad_sintax)
{
  t_get *link;
  t_get *last;

  if (!words)
    return (prev);
  if (IN('>', word->word) || IN('<', word->word))
    return (prev);
  if (!prev)
    if ((link = interpret_cmd(word, words, bad_sintax, &last)) == NULL)
      return (NULL);
  if (prev)
    if ((link = interpret_params(word, words, bad_sintax, &last)) == NULL)
      return (NULL);
  if (prev)
    prev->next = link;
  if (list_cmd(*words, words, last, bad_sintax) == NULL)
    return (nullify_link(link, NULL));
  return (link);
}

static BOOL	check_sintax(char **bad_sintax, BOOL null)
{
  if (null)
    *bad_sintax = my_strdup(UNMATCHED_PARENTS);
  return (NULL);
}

static BOOL	parents(t_get *word, t_get **words, t_cmd *link, char **bad_sintax)
{
  BOOL		no_word;
  t_word	*organize;

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
  if ((link->parents = orga(organize, bad_sintax, no_word)) == NULL)
    return (check_sintax(bad_sintax, no_word));
}

BOOL	cmd_part(t_get *word, t_get **words, t_cmd *link, char **bad_sintax)
{
  link->type = PARENTS;
  if (MATCH(words, "("))
    return (parents(word, words, link, bad_sintax));
  link->type = WORDS;
  if ((link->params = list_cmd(word, words, NULL, bad_sintax)) == NULL)
    if (!(IN('>', word) || IN('<', word)))
      return (FALSE);
  return (TRUE);
}
