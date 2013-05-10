/*
** redir.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 12:08:51 2013 vincent colliot
** Last update Fri May 10 13:52:26 2013 vincent colliot
*/

#include "bool.h"
#include "xmalloc.h"
#include "orga.h"
#include "string.h"
#include "error.h"

static FLAG redir_type(char *s)
{
  return ((NMATCH("<<", s)) ? (DLEFT) :
		 (NMATCH(">>", s)) ? (DRIGHT) :
		 (NMATCH("<", s)) ? (LEFT) :
		 (NMATCH(">", s)) ? (RIGHT) :
		 (0));
}

static BOOL link_redir(t_get *word, t_get **words, t_redir *link, char **bad_sintax)
{
  size_t	i;

  i = (!((word->word)[0] == '<') || !((word->word)[0] == '>'));
  if ((!IN('<', word->word) && !IN('>', word->word)) || word->inter == TRUE)
    {
      *bad_sintax = my_strdup(WRONG_REDIR);
      return (FALSE);
    }
  if (i)
    link->in = ((word->word)[0]) - '0';
  if (((word->word)[i + 1]) == '&')
    {
      link->type = ON_CANAL;
      link->out = ((word->word)[i + 2]) - '0';
    }
  link->redir = redir_type(word->word + i);
  *words = word->next;
  rm_words(word);
  if (!link->type)
    {
      word = *words;
      *words = word->next;
      link->file = word->word;
      free(word);
    }
  return (TRUE);
}

static void *nullify(t_redir *r)
{
  if (r->file)
    free(r->file);
  free(r);
  return (FALSE);
}

t_redir	*redir_part(t_get *words, t_redir *prev, char **bad_sintax,
		    BOOL *is_redir)
{
  t_redir	*link;

  if (!words)
    return (prev);
  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (nullify_words(words));
  link->next = NULL;
  link->file = NULL;
  link->type = 0;
  if (prev)
    prev->next = link;
  if (link_redir(words, &words, link, bad_sintax) == FALSE)
    {
      nullify_words(words);
      return (nullify(link));
    }
  if (link->type != ON_CANAL)
    link->type = ON_FILE;
  *is_redir = TRUE;
  if (redir_part(words, link, bad_sintax, is_redir) == NULL)
    return (nullify(link));
  return (link);
}

