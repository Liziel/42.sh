/*
** cd.c<2> for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 17 17:17:12 2013 vincent colliot
** Last update Fri May 17 19:17:43 2013 vincent colliot
*/

static BOOL	old_new(char **def, char *env)
{
  char	*apwd;

  if ((apwd = getcwd(NULL, 0)) == NULL)
    return (EXIT_FAILURE);
  free(*def);
  *def = my_stricat(env, apwd, '"');
  free(apwd);
}

static BOOL	set_old(char *env)
{
  char		**tab;
  size_t	i;

  i = 0;
  while (environ[i])
    {
      if (NMATCH(env, environ[i]))
	return (old_new(&(environ[i]), env));
      i++;
    }
  tab = environ;
  if ((environ = xmalloc(sizeof(char*) * (i + 2))) == NULL)
    return (FALSE);
  i = (unsigned long)(environ[i + 1] = NULL);
  while (tab[i])
    {
      environ[i] = tab[i];
      i++;
    }
  return (old_new(&(environ[i]), env));
}

static char	*new_pwd(t_words *wpwd)
{
  if (!wpwd)
    return (get_env(HOME));
  if (MATCH(wpwd->word, "-"))
    return (get_env(OLD_PWD)));
  return (wpwd->word);
}

static BOOL	set_new(char *new)
{
  if (chdir(new) == -1)
    {
      print_err(DIR_ERROR);
      print_err(cmd);
      return (EXIT_FAILURE);
    }
  return (set_old("PWD"));
}

int	cd(t_words *cmd, void *bool)
{
  char	*new;

  if ((new = new_pwd(cmd->next)) == NULL)
    {
      print_err(DIR_ERROR);
      print_err(cmd);
      return (EXIT_FAILURE);
    }
  if ((*(BOOL*)bool) = set_old("OLD_PWD") == FALSE)
    return (EXIT_FAILURE);
  if (set_new(new_pwd) == FALSE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
