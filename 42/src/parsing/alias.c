/*
** alias.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 14:25:12 2013 vincent colliot
** Last update Sat May 18 03:05:02 2013 vincent colliot
*/

int	grow_alias(char *s, t_alias *alias)
{
  t_alias	*fill;
  int		r;

  if (!s[0])
    return (0);
  if ((r = push_alias(s, alias)))
    return (r);
  return (grow_alias(s + my_sstrlen(s, "\"'|;<>()`")
		     + (s[my_sstrlen(s, "\"'|;<>()`")] != 0)
		     + hempty(s + my_sstrlen(s, "\"'|;<>()`")
			      + (s[my_sstrlen(s, "\"'|;<>()`")] != 0))
		     , alias));
}

BOOL	seed_alias(char *s, t_alias *alias)
{
  t_alias *mod;
  int	r;

  mod = alias;
  while (mod)
    {
      mod->w = 0;
      mod->n = 0;
      mod = mod->next;
    }
  r = 0;
  if (alias)
    while ((r = grow_alias(s + hempty(s), alias)) > 0);
  if (!r)
    return (TRUE);
  return (FALSE);
}
