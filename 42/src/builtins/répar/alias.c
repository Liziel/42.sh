/*
** alias.c<2> for  in /home/collio_v/rendu_svn/42.sh/42/src
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May 18 01:19:45 2013 vincent colliot
** Last update Sat May 18 03:45:54 2013 vincent colliot
*/

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

static BOOL valid_str(char *s)
{
  if (s[my_sstrlen(s, " \\\t\"'|;<>()`")] != 0)
    {



      return (FALSE);
    }
  return (TRUE);
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
    return (p_one(pnew));
  if (valid_str(cmd->word) == FALSE)
    return (EXIT_FAILURE);
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
