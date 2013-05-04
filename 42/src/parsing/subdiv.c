/*
** subdiv.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 21:20:47 2013 vincent colliot
** Last update Sat May  4 13:11:24 2013 vincent colliot
*/

#include "string.h"
#include "xmalloc.h"
#include "get.h"
#include "error.h"

static size_t work_on_quote(char *s, char **bad_sintax)
{
  char	quote[3];

  quote[0] = s[0];
  quote[1] = '\'';
  quote[2] = 0;
  if (!IN(quote[0], s + 1))
    *bad_sintax = my_strcat(UNMATCHED_TOKEN, quote);
  return (my_strilen(s + 1, quote[0]) + 2);
}

static size_t redir_lenth(char *s)
{
  size_t	n;

  n = IN(s[0], "012");
  n += 1;
  if (s[n] != '&')
    return (n);
  n += 1;
  if (IN(s[n], "012"))
    if (IN(s[n + 1], " \t"))
      return (n + 1);
  return (n - IN(s[n], "012"));
}

static size_t subdiv(char *s, char **bad_sintax)
{
  if (NMATCH("||", s) || NMATCH("&&", s) || NMATCH("<<", s) || NMATCH(">>", s))
    return (2);
  if (my_sstrlen(s, "<>") < my_sstrlen(s, " \t\"'|&;()`") &&
      (my_sstrlen(s, "<>") == 1 || !my_sstrlen(s, "<>")))
    return (redir_lenth(s));
  if (s[0] == '"' || s[0] == '\'')
    return (work_on_quote(s, bad_sintax));
  if (IN(s[0], ";|&<>()`"))
    return (1);
  if (NMATCH(s + my_strilen(s, '&'), "&&") && my_strilen(s, '&')
      < my_sstrlen(s, " \t\"'|;<>()`"))
    return (my_strilen(s, '&'));
  return (my_sstrlen(s, " \t\"'|&;<>()`"));
}

static void	*nullify_link(t_get *link)
{
  free(link);
  return (NULL);
}

static void	*nullify(t_get *link)
{
  free(link->word);
  free(link);
  return (NULL);
}

t_get	*subdivide(char *s, t_get *prev, char **bad_sintax)
{
  size_t l;
  t_get *link;

  if (!s)
    return (prev);
  if (!s[0])
    return (prev);
  if ((link = xmalloc(sizeof(*prev))) == NULL)
    return (NULL);
  s += hempty(s);
  l = subdiv(s, bad_sintax);
  if (*bad_sintax)
    return (nullify_link(link));
  if ((link->word = my_strndup(s, l)) == NULL)
    return (NULL);
  link->next = NULL;
  link->prev = prev;
  if (prev)
    prev->next = link;
  if (subdivide(s + my_strlen(link->word) + hempty(s + my_strlen(link->word)),
		link, bad_sintax) == NULL)
    return (nullify(link));
  return (link);
}

