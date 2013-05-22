/*
** read_cmds.c for 42 in /home/thomas_1//Projets/42.sh/42/src/edit_line
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Wed May 15 17:14:07 2013 pierre-yves thomas
** Last update Wed May 22 06:27:45 2013 vincent colliot
*/

#include <signal.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "edit_line.h"
#include "string.h"
#include "subdivide.h"
#include "orga.h"
#include "lexec.h"

static void	*built(char *str, char **bad_sintax, t_info *info, char **mod_s)
{
  t_get	*sub;

  if (seed_alias(str, info->alias, &str) == FALSE)
    return (NULL);
  if (grow_var(str, &str, 0, info) == FALSE)
    return (NULL);
  *mod_s = str;
  if ((sub = subdivide(str, NULL, bad_sintax)) == NULL)
    return (NULL);
  if ((sub = comment(sub, NULL)) == NULL)
    return (NULL);
  return (orga(sub, bad_sintax, NULL));
}

static BOOL	built_and_exec(char *str, t_info *info)
{
  t_jobs	*exec;
  char		*bad_sintax;

  exec = NULL;
  bad_sintax = NULL;
  if (!empty(str))
    if ((exec = built(str, &bad_sintax, info, &str)) == NULL)
      {
	if (bad_sintax)
	  fprintf(stderr, "%s\n", bad_sintax);
	if (bad_sintax)
	  free(bad_sintax);
	if (bad_sintax)
	  return (TRUE);
	return (!(info->st = EXIT_FAILURE));
      }
  free(str);
  return (pre_exec(exec, info));
}

static t_history *ctrlcget(t_info **info, t_history *history)
{
  static t_info *inf_save = NULL;
  static t_history *hist_save = NULL;

  if (*info)
   inf_save = *info;
  else
    *info = inf_save;
  if (history)
    hist_save = history;
  return (hist_save);
}

static void	catch_after(int num)
{
  (void)num;
}

int	read_cmds(t_info *info)
{
  BOOL			c;
  char			*str;
  t_history		*history;

  c = TRUE;
  history = ctrlcget(&info, NULL);
  my_putstr(info->termcaps.invi_cursor, 1);
  configure_signals();
  while (c && (str = usr_cmd(0, history, info->termcaps)))
    {
      my_putstr(info->termcaps.visi_cursor, 1);
      signal(SIGINT, catch_after);
      my_put_in_history(&history, str);
      history = ctrlcget(&info, history);
      info->hist = history;
      c = built_and_exec(str, info);
      configure_signals();
      my_putstr(info->termcaps.invi_cursor, 1);
    }
  my_putstr("exit", 1);
  free_history(history);
  my_putstr(info->termcaps.visi_cursor, 1);
  return (0);
}
