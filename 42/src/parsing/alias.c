/*
** alias.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 10 14:25:12 2013 vincent colliot
** Last update Sat May 18 03:41:50 2013 vincent colliot
*/

static void	extend(t_alias *link, size_t n, size_t ext)
{
  while (link->prev)
    link = link->prev
  while (link)
    {
      if (link->w < n && link->w + link->n > n)
	link->n += ext;
      link = link->next;
    }
}

static int	push_alias(char *s, t_alias *alias, char **mod, size_t n)
{
  char	*r;
  char	*r2;

  if (!alias)
    return (0);
  if (!(my_strlen(alias->name) == my_sstrlen(s, "\t ") &&
	NMATCH(alias->name, s)))
    return (push_alias(s, alias->next));
  if (alias->w <= n && alias->w + alias->n > n)
    return (push_alias(s, alias->next));
  extend(beg, n, my_strlen(alias->fill));
  if ((r = my_strndup(s, n)) == NULL && n != 0)
    return (-1);
  if ((r2 = my_strcat(r, alias->fill)) == NULL)
    return (-1);
  free(r);
  *mod = my_strcat(r2, s + my_strlen(alias->fill));
  free(r2);
  free(s);
  return (push_alias(s, alias->next, mod, n));
}

static int	grow_alias(char *s, t_alias *alias, size_t n, char **mod)
{
  t_alias	*fill;
  int		r;

  if (!s[0])
    return (0);
  if ((r = push_alias(s, alias, mod, n)))
    return (r);
  return (grow_alias(s + my_sstrlen(s, "\"'|;<>()`")
		     + (s[my_sstrlen(s, "\"'|;<>()`")] != 0)
		     + hempty(s + my_sstrlen(s, "\"'|;<>()`")
			      + (s[my_sstrlen(s, "\"'|;<>()`")] != 0))
		     , alias,
		     n + my_sstrlen(s, "\"'|;<>()`")
		     + (s[my_sstrlen(s, "\"'|;<>()`")] != 0)
		     + hempty(s + my_sstrlen(s, "\"'|;<>()`")
			      + (s[my_sstrlen(s, "\"'|;<>()`")] != 0)),
		     mod));
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
    while ((r = grow_alias(s + hempty(s), alias, hempty(s))) > 0);
  if (!r)
    return (TRUE);
  return (FALSE);
}
