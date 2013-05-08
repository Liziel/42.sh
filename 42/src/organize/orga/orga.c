/*
** orga.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May  2 19:44:26 2013 vincent colliot
** Last update Thu May  9 00:47:50 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"
#include "error.h"

static BOOL	dlaunch_cmd(t_exec *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if (!get_cmd(exec->pipes, bad_sintax))
    return (nullify_pipes(exec->pipes));
  return (dlaunch_cmd(exec->next, bad_sintax));
}

static BOOL	launch_cmd(t_jobs *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if (!dlaunch_cmd(exec->exec, bad_sintax))
    return (nullify_exec(exec->exec));
  return (launch_cmd(exec->next, bad_sintax));
}

static BOOL	launch_pipe(t_jobs *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if (!get_pipe(exec->exec, bad_sintax))
    return (nullify_exec(exec->exec));
  return (launch_pipe(exec->next, bad_sintax));
}

static BOOL	launch_exec(t_jobs *exec, char **bad_sintax)
{
  if (!exec)
    return (TRUE);
  if ((exec->exec = get_exec(exec->tmp, NULL, bad_sintax)) == NULL)
    return (FALSE);
  return (launch_exec(exec->next, bad_sintax));
}

t_jobs	*orga(t_get *words, char **bad_sintax, BOOL *null)
{
  t_jobs *exec;

  if ((*null = (!words)))
    return (NULL);
  if ((exec = get_jobs(words, NULL, bad_sintax)) == NULL)
    return (NULL);
  if (!launch_exec(exec, bad_sintax))
    return (NULL);
  if (!launch_pipe(exec, bad_sintax))
    return (NULL);
  if (!launch_cmd(exec, bad_sintax))
    return (NULL);
  return (exec);
}
