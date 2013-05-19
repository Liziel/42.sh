/*
** env_cmd.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:59:47 2013 thomas lecorre
** Last update Sun May 19 05:21:49 2013 vincent colliot
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"
#include "bool.h"
#include "xmalloc.h"

static void	env_i(void)
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

static BOOL	env_u(t_words *cmd)
{
  char	**tab;
  size_t i;
  size_t n;

  if (!cmd)
    return (!(BOOL)print_err("env: option requires an argument -- 'u'"));
  n = (i = 0);
  while (environ[i])
    if (MATCH(environ[i++], cmd->word))
      n = 1;
  if (!n)
    return (TRUE);
  if ((tab = xmalloc(sizeof(char*) * (i))) == NULL)
    return ((long)(environ = NULL));
  n = (i = 0);
  while (environ[i])
    {
      if (!(MATCH(environ[i], cmd->word)))
	tab[n++] = environ[i];
      else
	free(environ[i]);
      i++;
    }
  free(environ);
  environ = tab;
  return (TRUE);
}

static BOOL	env_s(t_words *cmd)
{
  char	*line;
  int	i;
  char	**tab;

  if (!cmd || !cmd->next)
    return (!(BOOL)print_err("env: option requires two argument -- 'u'"));
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

static BOOL get_opt(t_words *opt, t_words **call)
{
  *call = opt;
  if (!opt)
    return (TRUE);
  if (MATCH(opt->word, "-i"))
    {
      env_i();
      return (get_opt(opt->next, call));
    }
  if (MATCH(opt->word, "-u"))
    {
      if (env_u(opt->next))
	return (FALSE);
      return (get_opt(opt->next->next, call));
    }
  if (MATCH(opt->word, "-s"))
    {
      if (env_s(opt->next))
	return (FALSE);
      return (get_opt(opt->next->next->next, call));
    }
  if (MATCH(opt->word, "--help"))
    return (print_help());
  return (TRUE);
}

int	built_env(t_words *cmd, void *bool)
{
  int		r;
  char		**save;

  (void)bool;
  save = env_copy();
  if (get_opt(cmd, &cmd) == FALSE)
    return (EXIT_FAILURE);
  r = exec_env(cmd);
  destroy_env();
  environ = save;
  return (r);
}
