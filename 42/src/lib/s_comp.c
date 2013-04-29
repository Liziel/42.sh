/*
** s_comp.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 20:01:41 2013 vincent colliot
** Last update Mon Apr 29 20:31:33 2013 vincent colliot
*/

int	my_strcmp(const char *s1, const char *s2)
{
  size_t	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i])
    i++;
  return (s1[i] - s2[i]);
}

int	my_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && i < n - 1)
    i++;
  return (s1[i] - s2[i]);
}
