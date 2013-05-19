/*
** unsetenv.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:03:04 2013 thomas lecorre
** Last update Sun May 19 07:55:57 2013 vincent colliot
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"
#include "xlib.h"

static int  switch_env(char **tab)
{
  free(environ);
  environ = tab;
  return (EXIT_SUCCESS);
}

static BOOL deset(t_words *cmd, char *env)
{
  if (!cmd)
    return (FALSE);
  if (NMATCH(env, cmd->word)
      && env[my_strlen(cmd->word)] == '"')
    return (TRUE);
  return (deset(cmd->next, env));
}

int	built_unsetenv(t_words *cmd, void *null)
{
  char		**tab;
  size_t	i;
  size_t	n;

  (void)null;
  if (!cmd->next)
    return (my_putstr("(sh): unsetenv: Too few arguments.\n", 2) != 0);
  i = (n = 0);
  if (environ)
    while (environ[i])
      if (deset(cmd->next, environ[i++]))
	n++;
  if (i == n)
    return (switch_env(NULL));
  if ((tab = xmalloc(sizeof(char*) * (i - n + 1))) == NULL)
    return (EXIT_FAILURE);
  tab[i - n] = NULL;
  i = (n = 0);
  while (environ[i])
    {
      if (!deset(cmd->next, environ[i]))
	tab[n++] = environ[i];
      i++;
    }
  return (switch_env(tab));
}

/* int	unsetenv(t_words *cmd, void *alias) */
/* { */
/*   int	i; */
/*   int	n; */
/*   char	**tab; */

/*   n = 0; */
/*   if (cmd->next == NULL) */
/*     { */
/*       my_putstr("(sh): unsetenv: Too few arguments.\n"); */
/*       return (EXIT_FAILURE); */
/*     } */
/*   if (environ == NULL) */
/*     return (EXIT_FAILURE); */
/*   cmd = cmd->next; */
/*   while (cmd != NULL) */
/*     { */
/*       i = 0; */
/*       while (environ[i] != NULL) */
/* 	{ */
/* 	  if (cmd->word && NMATCH(cmd->word, environ[i])) */
/* 	    if (environ[i][my_strlen(cmd->word)] == '=') */
/* 	      { */
/* 		free(environ[i]); */
/* 		environ[i] = NULL; */
/* 		n++; */
/* 	      } */
/* 	  i++; */
/* 	} */
/*       cmd = cmd->next; */
/*     } */
/*   if ((tab = malloc(sizeof(char *) * (i - n + 1))) == NULL) */
/*     return (EXIT_FAILURE); */
/*   n = 0; */
/*   while (environ[i] != NULL) */
/*     { */
/*       if (environ[i]) */
/* 	tab[n++] = environ[i]; */
/*       i++; */
/*     } */
/*   tab[n] = NULL; */
/*   free(environ); */
/*   environ = tab; */
/*   return (EXIT_SUCCES); */
/* } */
