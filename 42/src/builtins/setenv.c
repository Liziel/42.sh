/*
** setenv.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 15:05:03 2013 thomas lecorre
** Last update Fri May 10 18:19:38 2013 thomas lecorre
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"

int	setenv(t_words *cmd, void *alias);
{
  char	*line;
  char	**tab;
  int	i;

  if (cmd->next == NULL)
    env(cmd, alias);
  cmd = cmd->next;
  else if (cmd->next)
    line = my_stricat(cmd->word, cmd->next->word, '=');
  else
    line = my_strcat(cmd->word, "=");
  i = -1;
  while (environ[++i] != NULL)
    if ((NMATCH(cmd->word, environ[i])) == 1)
      {
	free(environ[i]);
	environ[i] = line;
	return (EXIT_SUCCES);
      }
  if ((tab = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (EXIT_FAILURE);
  tab[i + 1] = NULL;
  i = -1;
  while (environ[++i] != NULL)
    tab[i] = environ[i];
  tab[i] = line;
  environ = tab;
  return (EXIT_SUCCES);
}
