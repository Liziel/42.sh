/*
** setenv.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 15:05:03 2013 thomas lecorre
** Last update Sun May 19 07:53:44 2013 vincent colliot
*/

#include <stdlib.h>
#include "bool.h"
#include "string.h"
#include "env.h"
#include "built.h"
#include "xlib.h"

static int fill_env(char **tab, t_words *cmd, char *s)
{
  size_t	i;
  BOOL		n;

  i = (n = FALSE);
  while (environ[i])
    {
      if (!(NMATCH(environ[i], cmd->word)
	    && environ[i][my_strlen(cmd->word)] == '"'))
	tab[i] = environ[i];
      else
	{
	  n = TRUE;
	  free(environ[i]);
	  tab[i] = my_stricat(cmd->word, s, '"');
	}
      i++;
    }
  if (n == FALSE)
    tab[i++] = my_stricat(cmd->word, s, '"');
  tab[i] = NULL;
  free(environ);
  environ = tab;
  return (EXIT_SUCCESS);
}

int	built_setenv(t_words *cmd, void *bool)
{
  size_t	n;
  size_t	i;
  char		**tab;

  (void)bool;
  if (cmd->next == ((void*)(n = (i = 0))))
    return (built_env(cmd, bool));
  cmd = cmd->next;
  if (cmd->next)
    if (cmd->next->next)
      return (my_putstr("(sh): setenv : Too many arguments.\n", 2) != 0);
  if (environ)
    while (environ[i])
      if (NMATCH(environ[i], cmd->word)
	  && environ[i][my_strlen(cmd->word)] == '"')
	n = 1;
  if ((tab = xmalloc(sizeof(char *) * (i + !n + 1))) == NULL)
    return (EXIT_FAILURE);
  if (cmd->next)
    return (fill_env(tab, cmd, cmd->next->word));
  return (fill_env(tab, cmd, NULL));
}

/* int	setenv(t_words *cmd, void *bool) */
/* { */
/*   char	*line; */
/*   char	**tab; */
/*   int	i; */

/*   if (cmd->next == NULL) */
/*     env_cmd(cmd, alias); */
/*   cmd = cmd->next; */
/*   if (cmd->next->next->next) */
/*     { */
/*       my_putstr("setenv : Too many arguments.\n"); */
/*       return (EXIT_FAILURE); */
/*     } */
/*   if (cmd->next) */
/*     line = my_stricat(cmd->word, cmd->next->word, '='); */
/*   else */
/*     line = my_strcat(cmd->word, "="); */
/*   if ((i = -(environ != NULL))) */
/*     while (environ[++i] != NULL)//awww je suis pas super fan..suffit que leur compilo soit diff de notre gcc et c'est mal interpéter == segfault */
/*       if ((NMATCH(cmd->word, environ[i])) == 1) */
/* 	{ */
/* 	  free(environ[i]); */
/* 	  environ[i] = line; */
/* 	  return (EXIT_SUCCES); */
/* 	} */
/*   if ((tab = xmalloc(sizeof(char *) * (i + 2))) == NULL) */
/*     return (EXIT_FAILURE); */
/*   tab[i + 1] = NULL; */
/*   if ((i = -(environ != NULL))) */
/*     while (environ[++i] != NULL) */
/*       tab[i] = environ[i]; */
/*   tab[i] = line; */
/*   free(environ); */
/*   environ = tab; */
/*   return (EXIT_SUCCES); */
/* } */
