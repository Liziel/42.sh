/*
** get_env.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun May  5 12:30:49 2013 vincent colliot
** Last update Sun May  5 12:36:24 2013 vincent colliot
*/

char	*get_env(char *s)
{
  size_t	i;

  i = 0;
  if (!environ)
    return (NULL);
  while (environ[i])
    {
      if (NMATCH(s, environ[i]))
	return (environ[i] + my_strilen(environ[i], '=') + 1);
      i++;
    }
  return (NULL);
}

char	*get_full_env(char *s)
{
  size_t	i;

  i = 0;
  if (!environ)
    return (NULL);
  while (environ[i])
    {
      if (NMATCH(s, environ[i]))
	return (environ[i]);
      i++;
    }
  return (NULL);
}
