/*
** cmd_part.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 18:33:37 2013 vincent colliot
** Last update Sun May 19 07:17:45 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"
#include "error.h"

static t_words	*nullify_link(t_words *link, BOOL f, void *last)
{
  t_words *next;

  if (!link || f || link == last)
    return (NULL);
  next = link->next;
  free(link);
  return (nullify_link(next, f, last));
}

static BOOL	add_redir(t_get *word, t_get **words, char **bad_sintax, t_cmd *link)
{
  t_redir *prev;

  prev = link->redir;
  if (prev)
    while (prev->next)
      prev = prev->next;
  if (prev)
    if ((prev->next = redir_part(word, words, bad_sintax)) == NULL)
      return (FALSE);
  if (!prev)
    if ((link->redir = redir_part(word, words, bad_sintax)) == NULL)
      return (FALSE);
  return (TRUE);
}

static t_words	*list_cmd(t_get *word, t_cmd *clink, t_words *prev, char **bad_sintax)
{
  BOOL		f;
  t_words	*link;

  if (!word)
    return (prev);
  link = prev;
  if (!((IN('>', word->word) || IN('<', word->word)) && !word->inter))
    {
      clink->type = WORDS;
      if ((clink->type = WORDS) && prev)
	if ((link = interpret_params(word, &word, &prev, bad_sintax)) == NULL)
	  return ((void*)(long)nullify_words(word));
      if ((clink->type = WORDS) && !prev)
	if ((link = interpret_cmd(word, &word, bad_sintax, &prev)) == NULL)
	  return ((void*)(long)nullify_words(word));
    }
  else
    {
      if ((f = add_redir(word, &word, bad_sintax, clink)) == FALSE)
	return (NULL);
      else
	return (list_cmd(word, clink, prev, bad_sintax));
    }
  if (list_cmd(word, clink, prev, bad_sintax) == NULL)
    return (nullify_link(link, f, (prev->next = NULL)));
  return (link);
}

static BOOL	check_sintax(char **bad_sintax, BOOL null, char *s)
{
  if (null)
    *bad_sintax = my_strdup(s);
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
  rm_words(word);
  if ((word = (*words)->prev) == NULL)
    return (check_sintax(bad_sintax, 1, ERROR_NEAR_PARENTS));
  if (MATCH(word->word, "("))
    return (check_sintax(bad_sintax, 1, ERROR_NEAR_PARENTS));
  word->next = NULL;
  word = (*words)->next;
  rm_words(*words);
  if ((link->parents = orga(organize, bad_sintax, &no_word)) == NULL)
    return (check_sintax(bad_sintax, no_word, UNMATCHED_PARENTS));
  while (word)
    if (!add_redir(word, &word, bad_sintax, link))
      return (FALSE);
  return (TRUE);
}

BOOL	cmd_part(t_get *word, t_get **words, t_cmd *link, char **bad_sintax)
{
  word->prev = NULL;
  link->type = PARENTS;
  if (MATCH(word->word, "("))
    return (parents(word, words, link, bad_sintax));
  link->type = OREDIR;
  link->redir = NULL;
  if ((link->params = list_cmd(word, link, NULL, bad_sintax)) == NULL)
    if (link->type != OREDIR || *bad_sintax)
      return (FALSE);
  return (TRUE);
}
