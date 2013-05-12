/*
** interpret_params.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:09:42 2013 vincent colliot
** Last update Sun May 12 21:55:56 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"

  /* if (NMATCH("`", word->word)) */
  /*   if ((params = back_quote(word, words, bad_sintax)) == NULL) */
  /*     return (NULL); */
t_words		*interpret_params(t_get *word, t_get **words, char **bad_sintax,
				  t_words **last)
{
  BOOL		no_match;
  t_words	*params;

  no_match = TRUE;
  if (!word->inter)
    if (match_them(word->word + last_occur(word->word, '/', '*') + IN('/', word->word),
		   my_strndup(word->word, last_occur(word->word, '/', '*')),
			      last, &no_match) == FALSE)
      if (no_match == FALSE)
	return (NULL);
  *words = word->next;
  if (no_match == TRUE)
    {
      if ((params = xmalloc(sizeof(*params))) == NULL)
	return (NULL);
      params->word = my_strdup(word->word);
      params->next = NULL;
      (*last)->next = params;
      *last = params;
    }
  free(word->word);
  free(word);
  return (*last);
}
