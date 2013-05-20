/*
** my_exit.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue May 14 18:10:48 2013 thomas lecorre
** Last update Mon May 20 18:00:29 2013 vincent colliot
*/

#include "bool.h"
#include "built.h"
#include "string.h"

int	built_exit(t_words *cmd, void *bool)
{
  (void)bool;
  if (cmd->next)
    if (cmd->next->word)
      return (my_getnbr(cmd->next->word));
  return (0);
}
