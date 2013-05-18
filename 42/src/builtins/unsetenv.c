/*
** unsetenv.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:03:04 2013 thomas lecorre
** Last update Sat May 18 12:42:29 2013 thomas lecorre
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"

int	unsetenv(t_words *cmd, void *alias)
{
  int	i;
  int	n;
  char	**tab;

  n = 0;
  if (cmd->next == NULL)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      return (EXIT_FAILURE);
    }
  if (environ == NULL)
    return (EXIT_FAILURE);
  cmd = cmd->next;
  while (cmd != NULL)
    {
      i = 0;
      while (environ[i] != NULL)
	{
	  if (cmd->word && NMATCH(cmd->word, environ[i]))
	    if (environ[i][my_strlen(cmd->word)] == '=')
	      {
		free(environ[i]);
		environ[i] = NULL;
		n++;
	      }
	  i++;
	}
      cmd = cmd->next;
    }
  if ((tab = malloc(sizeof(char *) * (i - n + 1))) == NULL)
    return (EXIT_FAILURE);
  n = 0;
  while (environ[i] != NULL)
    {
      if (environ[i])
	tab[n++] = environ[i];
      i++;
    }
  tab[n] = NULL;
  free(environ);
  environ = tab;
  return (EXIT_SUCCES);
}
