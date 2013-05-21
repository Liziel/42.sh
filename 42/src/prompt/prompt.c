/*
** prompt.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 20 22:23:52 2013 vincent colliot
** Last update Wed May 22 01:28:28 2013 vincent colliot
*/

#include "string.h"
#include "prompt.h"
#include "env.h"

size_t	prompt(BOOL b)
{
  size_t	n;
  char		*p;
  size_t	i;

  p = get_env("PS1");
  if (!p)
    p = "------>Prompt test\n[Sla.sh] ";
  i = 0;
  if (!b)
    while (IN('\n', p + i))
      i += my_strilen(p + i, '\n') + 1;
  n = 0;
  while (p[i + n] && (!b || IN('\n', p + i + n)))
    n++;
  write(1, p + i, n);
  return (n);
}
