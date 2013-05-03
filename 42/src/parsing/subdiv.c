/*
** subdiv.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 21:20:47 2013 vincent colliot
** Last update Thu May  2 19:37:21 2013 vincent colliot
*/

#include "string.h"
#include "xmalloc.h"
#include "get.h"

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

static size_t subdiv(char *s)
{
  if (NMATCH("||", s) || NMATCH("&&", s) || NMATCH("<<", s) || NMATCH(">>", s))
    return (2);
  if (my_sstrlen(s, "<>") < my_sstrlen(s, " \t|&;()`") &&
      (my_sstrlen(s, "<>") == 1 || !my_sstrlen(s, "<>")))
    return (redir_lenth(s));
  if (IN(s[0], ";|&<>()`"))
    return (1);
  if (NMATCH(s + my_strilen(s, '&'), "&&") && my_strilen(s, '&')
      < my_sstrlen(s, " \t|;<>()`"))
    return (my_strilen(s, '&'));
  return (my_sstrlen(s, " \t|&;<>()`"));
}

t_get	*subdivide(char *s, t_get *prev)
{
  t_get *link;

  if (!s)
    return (prev);
  if (!s[0])
    return (prev);
  if ((link = xmalloc(sizeof(*prev))) == NULL)
    return (NULL);
  s += hempty(s);
  link->word = my_strndup(s, subdiv(s));
  link->next = NULL;
  link->prev = prev;
  if (prev)
    prev->next = link;
  if (subdivide(s + my_strlen(link->word) + hempty(s + my_strlen(link->word)),
		link) == NULL)
    return (NULL);
  return (link);
}

