/*
** parse_built.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May  3 17:56:18 2013 thomas lecorre
** Last update Sun May 19 08:43:49 2013 vincent colliot
*/

#include "built.h"

void	init_built(t_call built[9])
{
  (built[0]).name = "alias";
  (built[0]).ptr = &built_alias;
  (built[1]).name = "cd";
  (built[1]).ptr = &built_cd;
  (built[2]).name = "echo";
  (built[2]).ptr = &built_echo;
  (built[3]).name = "env";
  (built[3]).ptr = &built_env;
  (built[4]).name = "exit";
  (built[4]).ptr = &my_exit;
  (built[5]).name = "setenv";
  (built[5]).ptr = &setenv;
  (built[6]).name = "unsetenv";
  (built[6]).ptr = &unsetenv;
  (built[7]).name = "unalias";
  (built[7]).ptr = &unalias;
  (built[8]).name = NULL;
  (built[8]).ptr = NULL;
}

void	*stock_tab(t_call *built)
{
  static t_call	*tab;

  if (built)
    tab = bult;
  return (tab);
}

int	builtins(t_words *cmd, void *alias)
{
  t_call	*built;

  if ((built = xmalloc(sizeof(t_call) * 9)) == NULL)
    return (-1);
  init_built(&built);
  stock_tab(&built);
  return (0);
}
