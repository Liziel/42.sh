/*
** s_print.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue Apr 30 15:59:03 2013 vincent colliot
** Last update Mon May 13 14:25:03 2013 vincent colliot
*/

#include <unistd.h>
#include "string.h"
#include "fd.h"

size_t	my_putstr(const char *s, FD out)
{
  size_t	i;

  i = 0;
  while (s[i])
    i++;
  write(out, s, i);
  return (i);
}

size_t	my_putstr(const char *s, const char *out)
{
  FD		f;
  size_t	i;

  i = 0;
  while (s[i])
    i++;
  if ((f = open(out, O_RDONLY)) != -1)
    write(out, s, i);
  if (f != -1)
    close(f);
  return (i);
}

size_t	print_err(const char *s)
{
  size_t i;

  i = 0;
  while (s[i])
    i++;
  return (write(W_ERR, s, i));
}
