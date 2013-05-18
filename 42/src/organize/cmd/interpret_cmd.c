/*
** interpret.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May  4 16:34:47 2013 vincent colliot
** Last update Sat May 18 20:06:59 2013 vincent colliot
*/

#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"
#include "error.h"
#include "env.h"

static char	*seek(char *path, char *cmd, char **bad_sintax)
{
  char		*dir;

  if (!path)
    return (NULL);
  if (!path[0])
    {
      *bad_sintax = my_strcat(UNKNOW_CMD, cmd);
      return (NULL);
    }
  if ((dir = my_strndup(path, my_strilen(path, ':'))) == NULL)
    return (NULL);
  if (in_directory(dir, cmd))
    return (dir);
  free(dir);
  if (!IN(':', path))
    {
      *bad_sintax = my_strcat(UNKNOW_CMD, cmd);
      return (NULL);
    }
  return (seek(path + my_strilen(path, ':') + IN(':', path), cmd, bad_sintax));
}

static char	*verify(char *cmd, char **bad_sintax)
{
  char *r;

  if (access(cmd, X_OK))
    {
      *bad_sintax = my_strcat(UNKNOW_CMD, cmd);
      return (NULL);
    }
  r = my_strdup(cmd);
  return (r);
}

static char	*seek_cmd(char *cmd, char **bad_sintax)
{
  char *r;
  char *wh;
  char *path;

  if ((path = get_env("PATH")) == NULL)
    *bad_sintax = my_strcat(UNKNOW_CMD, cmd);
  if ((wh = seek(path, cmd, bad_sintax)) == NULL)
    return (NULL);
  r = my_stricat(wh, cmd, '/');
  free(wh);
  return (r);
}

static void	*nullify_link(t_words *link)
{
  free(link);
  return (NULL);
}

static BOOL	not_a_built_in(char *word)
{
  (void)word;
  return (TRUE);
}

/*
** ce qu'il y a a intérpréter.... :: . || !. || builts-in and that's all...and `` later
*/
t_words		*interpret_cmd(t_get *word, t_get **words, char **bad_sintax,
			      t_words **last)
{
  t_words	*link;
  char		*cmd;

  cmd = NULL;
  /* if (NMATCH("`", word->word)) */
  /*   if ((cmd = back_quote(word, words, bad_sintax)) == NULL) */
  /*     return (NULL); */
  if (!cmd)
    cmd = word->word;
  if ((*last = (link = xmalloc(sizeof(*link)))) == NULL)
    return (NULL);
  if (cmd[0] == '.' || IN('/', cmd))
    if ((link->word = verify(cmd, bad_sintax)) == NULL)
      return (nullify_link(link));
  if (cmd[0] != '.' && not_a_built_in(cmd))
    if ((link->word = seek_cmd(cmd, bad_sintax)) == NULL)
      return (nullify_link(link));
  free(cmd);
  *words = word->next;
  free(word);
  link->next = NULL;
  return (link);
}
