/*
** s_memset.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 14 01:09:10 2013 vincent colliot
** Last update Tue May 14 01:23:29 2013 vincent colliot
*/

#include "string.h"

void	*my_memset(void *s, int k, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
    *(unsigned char *)(s + i) = k;
  return (s);
}

void	*my_realloc(void  *ptr, size_t pre, size_t new)
{
  size_t	i;
  void		*r;

  i = 0;
  r = xmalloc(n);
  while (i < new)
    {
      if (i < pre)
	r[i] = ptr[i];
      else
	r[i] = 0;
      i++;
    }
  free(ptr);
  return (i);
}
