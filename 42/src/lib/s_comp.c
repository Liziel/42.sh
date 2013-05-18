/*
** s_comp.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 20:01:41 2013 vincent colliot
** Last update Sat May 18 02:09:16 2013 vincent colliot
*/

#include "string.h"

int	my_strcmp(const char *s1, const char *s2)
{
  size_t	i;

  if (s1 == NULL)
    return (1);
  if (s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] == s2[i] && s1[i])
    i++;
  return (s1[i] - s2[i]);
}

int	my_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t	i;

  if (!n)
    return (0);
  i = 0;
  while (s1[i] == s2[i] && s1[i] && i < n - 1)
    i++;
  return (s1[i] - s2[i]);
}
