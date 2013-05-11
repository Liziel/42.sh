/*
** env_cmd.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:59:47 2013 thomas lecorre
** Last update Sun May 12 01:02:58 2013 vincent colliot
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"
#include "bool.h"

int	env_cmd(t_words *cmd, void *bool)
{
  size_t	i;

  i = 0;
  if (cmd->next == NULL)
    while (*environ)
      my_putstr((*environ)++);//environ ++ peut merder suivant les compilo (soit environ += 1 ou environ+=sizeof(*environ)?
  else
    (BOOL)(*bool) = TRUE;//pour pouvoir l'utiliser il faut indiquer le type dans lequel tu le déréférence!
  return (EXIT_SUCCES);
}
