/*
** prompt.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 20 22:23:52 2013 vincent colliot
** Last update Tue May 21 16:24:14 2013 vincent colliot
*/

#include "string.h"
#include "prompt.h"

void	prompt(BOOL b)
{
  char		*p;
  size_t	i;

  p = "------>Prompt test\n[Sla.sh] ";
  i = 0;
  if (!b)
    while (IN('\n', p + i))
      i += my_strilen(p + i, '\n') + 1;
  my_putstr(p + i, 1);
}
