/*
** env.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 14:24:55 2013 thomas lecorre
** Last update Fri May 10 16:57:05 2013 thomas lecorre
*/

#include <stdio.h>
#include <stdlib.h>
#include "env.h"
#include "built.h"

extern char **environ;

char	**env_copy()
{
  char	**tab;
  int	i;

  i = 0;
  while (environ[i] != NULL)
      i++;
  if ((tab = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  tab[i] = NULL;
  i = 0;
  while (environ[i] != NULL)
    {
      tab[i] = my_strdup(environ[i]);
      i++;
    }
  return (tab);
}
