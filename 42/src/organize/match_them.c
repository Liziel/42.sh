/*
** match_them.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May  8 01:48:11 2013 vincent colliot
** Last update Wed May  8 03:17:28 2013 vincent colliot
*/

static void	add(char *name, t_words **last, int *no_match)
{
  *no_match = 1;
}

static t_words  *add_and_last(char *m, char *dp, t_words **last, int *no_match)
{
  char	*s;

  if (m[0])
    s = my_stricat(dp, m, '/');
  else
    s = dp;
  add(s, last, no_match);
  free(dp);
  if (m[0])
    free(s);
  return (*last);
}

static BOOL	is_dir(char *dp)
{
  struct stat st;

  if (stat(dp, &st) == -1)
    return (FALSE);
  if ((sb.st_mode & S_IFMT) == S_IFDIR)
    return (TRUE);
  return (FALSE);
}

/*h*h*/
t_words	*match_them(char *m, char *dp, t_words **last, int *no_match)
{
  char		*f_dp;
  struct dirent	*fchr;
  DIR	*dir;

  if (!m[0] || !(IN('*', m)))
    return (add_and_last(m, dp, last, no_match));
  if (dp)
    dir = opendir(dp);
  else
    dir = opendir(".");
  while ((fchr = readdir(dir)) != NULL)
    if (((fchr->d_name)[0] == '.' && m[0] == '.') || (fchr->d_name)[0] != '.')
      if (nmatch(fchr->d_name, m, my_strilen(m, '/')))
	if ((f_dp = my_stricat(dp, fchr->d_name, '/')) == NULL)
	  return (NULL);
	else if ((IN('/', m) && is_dir(f_dp)) || !IN('/', m))
	  if (match_them(m + my_strilen(m, '/') + (IN('/', m)), f_dp, last,
			 no_match) == NULL)
	    return (NULL);
  closedir(dir);
  free(dp);
  if (!(*no_match))
    return (NULL);
  return (*last);
}
