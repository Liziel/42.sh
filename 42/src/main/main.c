/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Tue May 14 21:41:06 2013 vincent colliot
*/

#include <unistd.h>
#include <stdlib.h>
#include "get.h"
#include "orga.h"
#include "exec.h"
#include "string.h"

int main(void)
{
  char *test;
  BOOL	null;
  char  *bad_sintax;
  t_info	info;
  t_get *g;
  t_jobs	*j;

  bad_sintax = NULL;
  my_putstr("test>", 1);
  while (test = get_next_line(0))
    {
      bad_sintax = NULL;
      g = subdivide(test, NULL, &bad_sintax);
      if (comment(g) ==  FALSE)
	return (-1);
      if (bad_sintax)
	{
	  print_err(bad_sintax);
	  print_err("\n");
	}
      j = orga(g, &bad_sintax, &null);
      if (bad_sintax)
	{
	  print_err(bad_sintax);
	  print_err("\n");
	}
      info.st = EXIT_SUCCESS;
      if (!bad_sintax)
	pre_exec(j, &info);
      free(test);
      my_putstr("test>", 1);
    }
  return (0);
}
