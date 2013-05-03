/*
** match.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 16:56:48 2013 vincent colliot
** Last update Fri May  3 17:25:10 2013 vincent colliot
*/

#include "string.h"

size_t	my_strnslen(const char *s, const char *c, size_t n)
{
  size_t	i;

  i = 0;
  while (s[i] && my_strncmp(c, s, n))
    i++;
  return (i);
}

static BOOL	recur_match(const char *s, const char *c)
{
  size_t	l;

  if ((!s[0] && (!c[0] || MATCH(c, "*"))))
    return (TRUE);
  if (!IN('*', c))
    {
      if (my_strlen(s) < my_strlen(c))
	return (FALSE);
      if (MATCH(c, s + my_strlen(s) - my_strlen(c)))
	return (TRUE);
      else
	return (FALSE);
    }
  if (!LS_IN(c, s, my_strilen(c, '*')))
    return (FALSE);
  l = my_strilen(c, '*');
  s += my_strnslen(s, c, my_strilen(c, '*')) + my_strilen(c, '*');
  c += l + IN('*', c);
  return (recur_match(s, c));
}

BOOL	match(const char *s, const char *c)
{
  if (!(s && c))
    return (FALSE);
  if (!FNMATCH(s, c, my_strilen(c, '*')))
    return (FALSE);
  return (recur_match(s + my_strilen(c, '*'), c + my_strilen(c, '*')
		      + IN('*', c)));
}
