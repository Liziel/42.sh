/*
** null2.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May  9 21:50:54 2013 vincent colliot
** Last update Thu May  9 22:56:23 2013 vincent colliot
*/

#include <stdlib.h>
#include "orga.h"
#include "lexec.h"
#include "bool.h"

void *nullify_all_jobs(t_jobs *jobs)
{
  t_jobs	*next;

  if (!jobs)
    return (NULL);
  if (jobs->exec)
    nullify_all_exec(jobs->exec);
  else
    nullify_words(jobs->tmp);
  next = jobs->next;
  free(jobs);
  nullify_all_jobs(next);
  return (NULL);
}

BOOL nullify_jobs(t_jobs *jobs, BOOL ex)
{
  if (jobs->exec && !ex)
    nullify_all_exec(jobs->exec);
  else if (!ex)
    nullify_words(jobs->tmp);
  if (ex)
    nullify_exec(jobs->exec);
  free(jobs);
  return (FALSE);
}

void nullify_cmd_words(t_words *s)
{
  t_words *n;

  if (!s)
    return ;
  n = s->next;
  free(s->word);
  free(s);
  nullify_cmd_words(n);
}

BOOL nullify_cmd(t_cmd *cmd)
{
  if (!cmd)
    return (FALSE);
  if (cmd->params)
    nullify_cmd_words(cmd->params);
  else if (cmd->parents)
    nullify_all_jobs(cmd->parents);
  free(cmd);
  return (FALSE);
}

void	rm_words(t_get *w)
{
  free(w->word);
  free(w);
}
