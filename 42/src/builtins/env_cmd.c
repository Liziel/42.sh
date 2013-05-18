/*
** env_cmd.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:59:47 2013 thomas lecorre
** Last update Sat May 18 13:20:28 2013 thomas lecorre
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
  char	*line;
  int	i;
  char	**tab;

  if (!cmd->next)
    return (FALSE);
  line = my_stricat(cmd->word, cmd->next->word, '=');
  if ((i = -(environ != NULL)))
    while (environ[++i])
      if ((NMATCH(cmd->word, environ[i])) == 1)
	{
	  free(environ[i]);
	  environ[i] = line;
	  return (TRUE);
	}
  if ((tab = xmalloc(sizeof(char *) * (i + 2))) == NULL)
    return (FALSE);
  tab[i + 1] = NULL;
  if ((i = -(environ != NULL)))
    while (environ[++i] != NULL)
      tab[i] = environ[i];
  tab[i] = line;
  free(environ);
  environ = tab;
  return (TRUE);
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
