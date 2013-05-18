/*
** alias.c<2> for  in /home/collio_v/rendu_svn/42.sh/42/src
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May 18 01:19:45 2013 vincent colliot
** Last update Sat May 18 02:19:44 2013 vincent colliot
*/

int mod_alias(char *a, char *f, t_alias **alias)
{
  t_alias *put;
  t_alias *link;

  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (EXIT_FAILURE);
  if ((link->name = my_strdup(a)) == NULL)
    return (EXIT_FAILURE);
  if ((link->fill = my_strdup(f)) == NULL)
    return (EXIT_FAILURE);
  if (my_strcmp((*alias)->name, a) > 0)
    {
      link->next = *alias;
      *alias = link;
      return (EXIT_SUCCESS);
    }
  put = *alias;
  while (put)
    {
      if (!put->next)
	return (add_after(put, link));
      else if (my_strcmp(put->next->name, a) > 0)
	return (add_after(put, link));
      put = put->next;
    }
  return (EXIT_SUCCESS);
}

static int p_one(t_alias *alias)
{
  if (!alias)
    return (EXIT_FAILURE);
  my_putstr("alias ");
  my_putstr(alias->name);
  my_pustr("=\"");
  my_putstr(alias->fill);
  my_putstr("\"\n");
  return (EXIT_SUCCESS);
}

static int get_n(t_words *cmd, t_alias *alias, t_alias **mod)
{
  t_alias	*pnew;

  pnew = NULL;
  while (alias)
    {
      if (MATCH(cmd->word, alias->name))
	pnew = alias;
      alias = alias->next;
    }
  if (!cmd->next)
    return (p_one(alias));
  if (!pnew)
    return (mod_alias(cmd->word, cmd->next->word, mod));
  free(pnew->fill);
  if ((pnew->fill = my_strdup(cmd->next->word)) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

static int print(t_alias *deb)
{
  if (!alias)
    return (EXIT_SUCCESS);
  p_one(alias);
  return (print(alias->next));
}

int	alias(t_words *cmd, t_alias **alias)
{
  if (!cmd->next)
    return (print(*alias));
  return (get_n(cmd->next, *alias, alias));
}
