/*
** unsetenv.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:03:04 2013 thomas lecorre
** Last update Fri May 10 17:45:46 2013 thomas lecorre
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
  cmd = cmd->next;
  while (cmd != NULL)
    {
      i = -1;
      while (environ[++i] != NULL)
	{
	  if (cmd->word && (NMATCH(cmd->word, environ[i])) == 1)
	    {
	      free(environ[i]);
	      n++;
	    }
	}
      cmd = cmd->next;
    }
  if ((tab = malloc(sizeof(char *) * (i - n + 1))) == NULL)
    return (EXIT_FAILURE);
  tab[i - n] = NULL;
  i = -1;
  while (environ[++i] != NULL)
    if (environ[i])
      tab[i] = environ[i];
  environ = tab;
  return (EXIT_SUCCES);
}
