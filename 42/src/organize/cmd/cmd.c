/*
** cmd.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May  2 22:05:00 2013 vincent colliot
** Last update Tue May 14 01:06:09 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"

static t_cmd	*nullify_link(t_cmd *cmd)
{
  free(cmd);
  return (NULL);
}

static t_cmd	*make_cmd(t_get *words, char **bad_sintax)
{
  t_cmd		*link;

  if (!words)
    return (NULL);
  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (NULL);
  link->redir = NULL;
  link->params = NULL;
  link->parents = NULL;
  if (!cmd_part(words, &words, link, bad_sintax))
    {
      nullify_redir(link->redir);
      return (nullify_link(link));
    }
  return (link);
}

BOOL	get_cmd(t_pipes *pipe, char **bad_sintax)
{
  if (!pipe)
    return (TRUE);
  if ((pipe->cmd = make_cmd(pipe->tmp, bad_sintax)) == NULL)
    {
      nullify_all_pipes(pipe->next);
      free(pipe);
      return (FALSE);
    }
  if (get_cmd(pipe->next, bad_sintax) == NULL)
    return (nullify_all_in_pipes(pipe));
  return (TRUE);
}
