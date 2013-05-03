/*
** orga.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May  2 19:44:26 2013 vincent colliot
** Last update Fri May  3 01:41:47 2013 vincent colliot
*/

static BOOL	dlaunch_cmd(t_exec *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if (!get_cmd(exec->pipe, bad_sintax))
    return (FALSE);
  return (launch_exec(exec->next, bad_sintax));
}

static BOOL	launch_cmd(t_jobs *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if (!dlaunch_cmd(exec->exec, bad_sintax))
    return (FALSE);
  return (launch_exec(exec->next, bad_sintax));
}

static BOOL	launch_pipe(t_jobs *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if (!get_pipe(exec->exec, bad_sintax))
    return (FALSE);
  return (launch_exec(exec->next, bad_sintax));
}

static BOOL	launch_exec(t_jobs *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if ((exec->exec = get_exec(exec->tmp, NULL, bad_sintax)) == NULL)
    return (FALSE);
  return (launch_exec(exec->next, bad_sintax));
}

t_exec	*orga(t_get *words, char **bad_sintax, BOOL *null)
{
  t_jobs *exec;

  if ((*null = !words))
    return (NULL);
  if ((exec = get_jobs(words, NULL, bad_sintax)) == NULL)
    return (NULL);
  if (!launch_exec(words, NULL, bad_sintax))
    return (NULL);
  if (!get_pipe(exec, bad_sintax))
    return (NULL);
  if (!get_cmd(exec, bad_sintax))
    return (NULL);
}
