/*
** env_cmd.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:59:47 2013 thomas lecorre
** Last update Sat May 18 12:48:09 2013 thomas lecorre
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"
#include "bool.h"

void	env_i(void)
{
  int	i;

  i = 0;
  if (!environ)
    return ;
  while (environ[i])
    {
      free(environ[i]);
      i++;
    }
  free(environ);
  environ = NULL;
}

BOOL	env_u(t_words *cmd)
{
  int	i;
  int	n;
  char	**tab;

  i = 0;
  if (!cmd)
    return (FALSE);
  while (environ[i])
    {
      if (cmd->word && NMATCH(cmd->word, environ[i]))
	if (environ[i][my_strlen(cmd->word)] == '=')
	  {
	    free(environ[i]);
	    environ[i] = NULL;
	  }
      i++;
    }
  if ((tab = malloc(sizeof(char *) * (i))) == NULL)
    return (EXIT_FAILURE);
  tab[i - 1] = NULL;
  n = i;
  i = 0;
  while (n < i)
    {
      if (environ[i])
	tab[n++] = environ[i];
      i++;
    }
  tab[n] = NULL;
  free(environ);
  environ = tab;
  return (TRUE);

}

BOOL	env_s(t_words *cmd)
{

}

int	env_cmd(t_words *cmd, void *bool)
{
  size_t	i;
  char		**save;

  i = 0;
  save = env_copy();
  if (get_opt(cmd, &cmd) == FALSE)
    return (EXIT_FAILURE);
  environ = save;
  return (EXIT_SUCCES);
}
