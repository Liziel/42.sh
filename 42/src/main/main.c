/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Fri May  3 17:38:55 2013 vincent colliot
*/

#include <stdlib.h>
#include "get.h"

int main(void)
{
  t_get *g;

  g = subdivide("   \t  ls  toto>tata  | (slaut     1>     1>&1eh ba non  )        caca;plop>no&& noo || lol||n", NULL);
  printf("%d\n", match("toto.c", "*"));
  printf("%d\n", match("toto.c", "*.c"));
  printf("%d\n", match("toto.c", "**.c"));
  printf("%d\n", match("tototo.c", "to*to.c"));
  printf("%d\n", match("totato.c", "*ta*.c"));
  printf("%d\n", match("tototo.c", "to*to*to.c"));
  printf("%d\n", match("toto.c", "toto**"));
  return (0);
}
