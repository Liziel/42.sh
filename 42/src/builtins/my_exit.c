/*
** my_exit.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue May 14 18:10:48 2013 thomas lecorre
** Last update Tue May 14 18:20:24 2013 thomas lecorre
*/

#include "bool.h"
#include "built.h"

int	my_exit(t_words *cmd, void *bool)
{
  *((BOOL*)bool) = TRUE
  if (cmd->next)
    if (cmd->next->word)
      return (my_getnbr(cmd->next->word));
  return (0);
}
