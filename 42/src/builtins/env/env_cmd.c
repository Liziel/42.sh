/*
** env_cmd.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May 10 17:59:47 2013 thomas lecorre
** Last update Sat May 18 20:31:00 2013 vincent colliot
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
    return (FALSE);
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

BOOL	env_s(t_words *cmd)
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

BOOL get_opt(t_word *opt, t_word **call)
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

int	env_cmd(t_words *cmd, void *bool)
{
  size_t	i;
  char		**save;

  (void)bool;
  i = 0;
  save = env_copy();
  if (get_opt(cmd, &cmd) == FALSE)
    return (EXIT_FAILURE);
  environ = save;
  return (EXIT_SUCCES);
}
