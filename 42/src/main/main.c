/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Wed May  8 03:01:18 2013 vincent colliot
*/

#include <stdlib.h>
#include "get.h"

int main(void)
{
  char  *bad_sintax;
  t_get *g;

  bad_sintax = NULL;
  g = subdivide("   \t  ls\\  1\\<2& toto>tata  |\\ (slaut     \"1>     1>&1eh\" ba non  ) &&       caca;plop>no&& noo || lol||n\\\"", NULL, &bad_sintax);
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
