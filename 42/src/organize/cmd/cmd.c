/*
** cmd.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May  2 22:05:00 2013 vincent colliot
** Last update Sun May 12 20:33:43 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"

static t_cmd	*nullify_link(t_cmd *cmd, t_get *word, BOOL fword)
{
  t_get		*next;

  next = word;
  while (next && fword)
    {
      next = word->next;
      free(word->word);
      free(word);
      word = next;
    }
  free(cmd);
  return (NULL);
}

static t_cmd	*make_cmd(t_get *words, char **bad_sintax)
{
  BOOL		is_redir;
  t_cmd		*link;

  if (!words)
    return (NULL);
  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (NULL);
  link->redir = NULL;
  link->params = NULL;
  link->parents = NULL;
  is_redir = FALSE;
  if (!cmd_part(words, &words, link, bad_sintax))
    return (nullify_link(link, words, 1));
  if ((link->redir = redir_part(words, NULL, bad_sintax, &is_redir)) == NULL)
    if (is_redir)
      return (nullify_link(link, words, 0));
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
