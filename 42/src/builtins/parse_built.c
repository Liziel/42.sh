/*
** parse_built.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May  3 17:56:18 2013 thomas lecorre
** Last update Thu May  9 12:23:21 2013 thomas lecorre
*/

#include "built.h"

void	init_built(t_call *built)
{
  built[0]->name = my_strdup("cd");
  built[1]->name = my_strdup("echo");
  built[2]->name = my_strdup("exit");
  built[3]->name = my_strdup("setenv");
  built[4]->name = my_strdup("unsetenv");
}

int	builtins()
{
  t_call	built[5];

  init_built(&built);
  return (0);
}
