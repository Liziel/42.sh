/*
** s_alloc.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 19:47:25 2013 vincent colliot
** Last update Tue Apr 30 15:58:44 2013 vincent colliot
*/

#include "string.h"

char	*my_strdup(const char *s)
{
  char		*r;
  size_t	i;

  i = 0;
  if (!s)
    return (NULL);
  if ((r = malloc(sizeof(*r) * (my_strlen(s) + 1))) == NULL)
    {
      print_err("Sys fail\n");
      return (NULL);
    }
  while (s[i])
    {
      r[i] = s[i];
      i++;
    }
  return (r);
}

void	*my_strndup(const void	*s, size_t n)
{
  void	*r;
  size_t	i;

  i = 0;
  if (!s)
    return (NULL);
  if ((r = malloc(n)) == NULL)
    {
      print_err("Sys fail\n");
      return (NULL);
    }
  while (i < n)
    {
      ((char*)r)[i] = ((char*)s)[i];
      i++;
    }
  return (r);
}
