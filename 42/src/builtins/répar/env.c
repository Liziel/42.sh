/*
** env.c for  in
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May 18 11:54:27 2013 vincent colliot
** Last update Sat May 18 12:27:40 2013 vincent colliot
*/

static BOOL	print_help(void)
{
  my_putstr("Uasge: env [options]\n", 1);
  my_putstr("env built-in loads a temporary environment, wich is setted by:\n",
	    1);
  my_putstr("    -i      : unset all\n", 1);
  my_putstr("    -u {p}  : unset {p}\n", 1);
  my_putstr("    -s {v,p}: set {v} with {p}\n", 1);
  return (TRUE);
}

BOOL get_opt(t_word *opt, t_word **call)
{
  *call = opt;
  if (!opt)
    return (TRUE);
  if (MATCH(opt->word, "-i"))
    {
      env_i();
      return (get_opt(opt->next, call));
    }
  if (MATCH(opt->word, "-u"))
    {
      if (env_u(opt->next))
	return (FALSE);
      return (get_opt(opt->next->next, call));
    }
  if (MATCH(opt->word, "-s"))
    {
      if (env_s(opt->next))
	return (FALSE);
      return (get_opt(opt->next->next->next, call));
    }
  if (MATCH(opt->word, "--help"))
    return (print_help());
  return (TRUE);
}
