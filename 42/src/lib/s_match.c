/*
** s_match.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 20:15:24 2013 vincent colliot
** Last update Fri May  3 16:57:13 2013 vincent colliot
*/

#include "string.h"

BOOL	empty(const char *s)
{
  size_t	i;

  i = 0;
  while (s[i] == ' ' || s[i] == 9)
    i++;
  return (s[i] == '\0');
}

BOOL	nempty(const char *s, size_t n)
{
  size_t	i;

  i = 0;
  while ((s[i] == ' ' || s[i] == 9) && i < n)
    i++;
  return (s[i] == '\0' || i == n);
}

size_t	hempty(const char *s)
{
  size_t	i;

  i = 0;
  while (s[i] == ' ' || s[i] == 9)
    i++;
  return (i);
}
