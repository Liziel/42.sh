/*
** s_print.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue Apr 30 15:59:03 2013 vincent colliot
** Last update Mon May  6 22:35:02 2013 vincent colliot
*/

#include <unistd.h>
#include "string.h"
#include "fd.h"

size_t	print_err(const char *s)
{
  size_t i;

  i = 0;
  while (s[i])
    i++;
  return (write(W_ERR, s, i));
}
