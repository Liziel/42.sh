/*
** setenv.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 15:05:03 2013 thomas lecorre
** Last update Sat May 18 12:18:04 2013 thomas lecorre
*/

#include <stdlib.h>
#include "bool.h"
#include "string.h"
#include "env.h"
#include "built.h"

int	setenv(t_words *cmd, void *bool);
{
  char	*line;
  char	**tab;
  int	i;

  if (cmd->next == NULL)
    env_cmd(cmd, alias);
  cmd = cmd->next;
  if (cmd->next->next->next)
    {
      my_putstr("setenv : Too many arguments.\n");
      return (EXIT_FAILURE);
    }
  if (cmd->next)
    line = my_stricat(cmd->word, cmd->next->word, '=');
  else
    line = my_strcat(cmd->word, "=");
  if ((i = -(environ != NULL)))
    while (environ[++i] != NULL)//awww je suis pas super fan..suffit que leur compilo soit diff de notre gcc et c'est mal interpéter == segfault
      if ((NMATCH(cmd->word, environ[i])) == 1)
	{
	  free(environ[i]);
	  environ[i] = line;
	  return (EXIT_SUCCES);
	}
  if ((tab = xmalloc(sizeof(char *) * (i + 2))) == NULL)
    return (EXIT_FAILURE);
  tab[i + 1] = NULL;
  if ((i = -(environ != NULL)))
    while (environ[++i] != NULL)
      tab[i] = environ[i];
  tab[i] = line;
  free(environ);
  environ = tab;
  return (EXIT_SUCCES);
}
