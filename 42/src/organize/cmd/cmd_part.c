/*
** cmd_part.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 18:33:37 2013 vincent colliot
** Last update Wed May 15 01:54:19 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"
#include "error.h"

static t_words	*nullify_link(t_words *link, BOOL f)
{
  t_words *next;

  if (!link || f)
    return (NULL);
  next = link->next;
  free(link);
  return (nullify_link(next, f));
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

  f = FALSE;
  if (!word)
    return (prev);
  link = prev;
  if (!((IN('>', word->word) || IN('<', word->word)) && !word->inter))
    {
      if (prev)
	if ((link = interpret_params(word, &word, &prev)) == NULL)
	  return ((void*)(long)nullify_words(word));
      if (!prev)
	if ((link = interpret_cmd(word, &word, bad_sintax, &prev)) == NULL)
	  return ((void*)(long)nullify_words(word));
    }
  else
    if ((f = add_redir(word, &word, bad_sintax, clink)) == FALSE)
      return (NULL);
  if (list_cmd(word, clink, prev, bad_sintax) == NULL)
    {
	prev->next = NULL;
      return (nullify_link(link, f));
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

  if (match_parents(words, bad_sintax) == FALSE)
    return (FALSE);
  if ((organize = word->next))
    word->next->prev = NULL;
  rm_words(word);
  if ((word = *words) == NULL)
    return (FALSE);
  if (word->prev)
    word->prev->next = NULL;
  *words = word->next;
  rm_words(word);
  if ((link->parents = orga(organize, bad_sintax, &no_word)) == NULL)
    return (check_sintax(bad_sintax, no_word));
  return (TRUE);
}

BOOL	cmd_part(t_get *word, t_get **words, t_cmd *link, char **bad_sintax)
{
  word->prev = NULL;
  link->type = PARENTS;
  if (MATCH(word->word, "("))
    return (parents(word, words, link, bad_sintax));
  link->type = WORDS;
  link->redir = NULL;
  if ((link->params = list_cmd(word, link, NULL, bad_sintax)) == NULL)
    return (FALSE);
  return (TRUE);
}
