/*
** parse_built.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May  3 17:56:18 2013 thomas lecorre
** Last update Sun May 12 00:50:17 2013 vincent colliot
*/

#include "built.h"
/*
**niquel! euh par contre et pour env_cmd?
**/
void	init_built(t_call built[5])
{
  (built[0]).name = my_strdup("cd");
  (built[0]).ptr = &cd;
  (built[1]).name = my_strdup("echo");
  (built[1]).ptr = &echo;
  (built[2]).name = my_strdup("exit");
  (built[2]).ptr = &exit;
  (built[3]).name = my_strdup("setenv");
  (built[3]).ptr = &setenv;
  (built[4]).name = my_strdup("unsetenv");
  (built[4]).ptr = &unsetenv;
  (built[5]).name = my_strdup("alias");
  (built[5]).ptr = &alias;
  (built[6]).name = NULL;
  (built[6]).ptr = NULL;
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

  if ((built = xmalloc(sizeof(t_call) * 7)) == NULL)
    return (-1);
  init_built(&built);
  stock_tab(&built);
  return (0);
}
