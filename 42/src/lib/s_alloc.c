/*
** s_alloc.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 19:47:25 2013 vincent colliot
** Last update Sat May  4 13:08:02 2013 vincent colliot
*/

#include "string.h"
#include "xmalloc.h"

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
  if ((r = malloc(n + 1)) == NULL)
    {
      print_err("Sys fail\n");
      return (NULL);
    }
  ((char*)r)[n] = 0;
  while (i < n)
    {
      ((char*)r)[i] = ((char*)s)[i];
      i++;
    }
  return (r);
}

char	*my_strcat(const char *s, const char *c)
{
  size_t i;
  size_t si;
  size_t ci;
  char	*r;

  si = my_strlen(s);
  ci = my_strlen(c);
  if ((r = xmalloc(sizeof(char) * (si + ci + 1))) == NULL)
    return (NULL);
  r[si + ci] = 0;
  i = 0;
  while (i < si)
    {
      r[i] = s[i];
      i++;
    }
  while (i < si + ci)
    {
      r[i] = c[i - si];
      i++;
    }
  return (r);
}
