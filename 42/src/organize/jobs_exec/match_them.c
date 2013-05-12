/*
** match_them.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May  8 01:48:11 2013 vincent colliot
** Last update Sun May 12 21:42:03 2013 vincent colliot
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "orga.h"
#include "lexec.h"
#include "bool.h"
#include "string.h"
#include "xmalloc.h"
#include "error.h"

static BOOL	add(char *name, t_words **last, BOOL *no_match)
{
  t_words	*link;

  if (!name)
    return (FALSE);
  *no_match = FALSE;
  if ((link = xmalloc(sizeof(*link))) == NULL)
    return (FALSE);
  link->word = my_strdup(name);
  link->next = NULL;
  (*last)->next = link;
  *last = link;
  return (TRUE);
}

static BOOL  add_and_last(char *m, char *dp, t_words **last, BOOL *no_match)
{
  char	*s;

  if (m[0] && (dp) != NULL)
    s = my_stricat(dp, m, '/');
  else if (dp != NULL)
    s = dp;
  else
    s = my_strdup(m);
  if (add(s, last, no_match) == FALSE)
    return (FALSE);
  if (dp)
    free(dp);
  if (m[0])
    free(s);
  return (TRUE);
}

static BOOL	is_dir(char *dp)
{
  struct stat st;

  if (stat(dp, &st) == -1)
    return (FALSE);
  if ((st.st_mode & S_IFMT) == S_IFDIR)
    return (TRUE);
  return (FALSE);
}

static BOOL	cond(struct dirent *fchr, char *m)
{
  if (nmatch(fchr->d_name, m, my_strilen(m, '/'))
      && (!(MATCH(fchr->d_name, ".") || MATCH(fchr->d_name, ".."))
	  || !IN('/', m)))
    return (TRUE);
  return (FALSE);
}

BOOL	match_them(char *m, char *dp, t_words **last, BOOL *no_match)
{
  char		*f_dp;
  struct dirent	*fchr;
  DIR	*dir;

  if (!m[0] || !(IN('*', m)))
    return (add_and_last(m, dp, last, no_match));
  if (dp)
    dir = opendir(dp);
  else
    dir = opendir(".");
  while ((fchr = readdir(dir)) != NULL)
    if (((fchr->d_name)[0] == '.' && m[0] == '.') || ((fchr->d_name)[0] != '.'
						      && m[0] != '.'))
      if (cond(fchr, m))
	{
	  if ((f_dp = my_stricat(dp, fchr->d_name, '/' * (dp != NULL))) == NULL)
	    return (FALSE);
	  else if ((IN('/', m) && is_dir(f_dp)) || !IN('/', m))
	    if (match_them(m + my_strilen(m, '/') + (IN('/', m)), f_dp, last,
			   no_match) == FALSE)
	      return (FALSE);
	}
  closedir(dir);
  if (dp)
    free(dp);
  return (!(*no_match));
}
