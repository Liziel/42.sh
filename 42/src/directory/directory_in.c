/*
** directory_in.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun May  5 13:18:32 2013 vincent colliot
** Last update Wed May  8 02:38:40 2013 vincent colliot
*/


BOOL	in_directory(char *dir, char *word)
{
  struct dirent	*fchr;
  DIR		*dir;

  if ((dir = opendir(dir)) == NULL)
    return (FALSE);
  while ((fchr = readdir(dir)) != NULL)
    if (MATCH(fchr->d_name, word))
      {
	closedir(dir);
	return (TRUE);
      }
  closedir(dir);
  return (FALSE);
}

/*
**ça match que le premier mais bon je vais en faire un mieux après
*/
BOOL	match_directory(char *dir, char *word, char **true_word)
{
  struct dirent	*fchr;
  DIR		*dir;

  if ((dir = opendir()) == NULL)
    return (FALSE);
  while ((fchr = readdir(dir)) != NULL)
    if (match(fchr->d_name, word))
      {
	if (true_word)
	  *true_word = my_strndup(fchr->d_name);
	closedir(dir);
	return (TRUE);
      }
  closedir(dir);
  return (FALSE);
}
