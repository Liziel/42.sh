/*
** nullify.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May  3 18:25:28 2013 vincent colliot
** Last update Thu May  9 00:43:28 2013 vincent colliot
*/

#include <stdlib.h>
#include "lexec.h"
#include "bool.h"

BOOL	nullify_exec(t_exec *exec)
{
  if (!exec)
    return (FALSE);
  free(exec);
  nullify_exec(exec->next);
  return (FALSE);
}

BOOL	nullify_pipes(t_pipes *pipes)
{
  if (!pipes)
    return (FALSE);
  free(pipes);
  nullify_pipes(pipes->next);
  return (FALSE);
}
