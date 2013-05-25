/*
** scan.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 23 14:23:19 2013 vincent colliot
** Last update Thu May 23 15:15:57 2013 vincent colliot
*/

FD	open_it(void)
{
  FD	file;
  char	*name;

  name = my_strcat(get_env("HOME"), ".Slashrc");
  file = open(name, O_RDONLY);
  free(name);
  return (fill);
}

void	scan_export(t_alias **alias)
{
  t_scan	scan;
  char		*s;
  FD		file;

  file = open_it();
  while ((s = get_next_line(file)) != NULL)
    treat_it(FD, s);
}
