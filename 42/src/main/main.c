/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Fri May 10 13:32:51 2013 vincent colliot
*/

#include <stdlib.h>
#include "get.h"
#include "orga.h"

int main(void)
{
  BOOL	null;
  char  *bad_sintax;
  t_get *g;
  t_jobs	*j;

  bad_sintax = NULL;
  g = subdivide("ls -l -a -R 1>&2 2>> tata; (ls -r | (cat -e) && no)", NULL, &bad_sintax);
  if (bad_sintax)
    print_err(bad_sintax);
  j = orga(g, &bad_sintax, &null);
  if (bad_sintax)
    print_err(bad_sintax);
  printf("%d\n", match("toto.c", "*c"));
  printf("%d\n", nmatch("toto.c", "t*/", my_strilen("t*/", '/')));
  printf("%d\n", match("toto.c", "*.c"));
  printf("%d\n", match("toto.c", "**.c"));
  printf("%d\n", match("tototo.c", "to*to.c"));
  printf("%d\n", match("totato.c", "*ta*.c"));
  printf("%d\n", match("tototo.c", "to*to*to.c"));
  printf("%d\n", match("toto.c", "toto**"));
  return (0);
}
