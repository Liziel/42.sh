/*
** read_cmds.c for 42 in /home/thomas_1//Projets/42.sh/42/src/edit_line
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Wed May 15 17:14:07 2013 pierre-yves thomas
** Last update Sat May 18 18:36:31 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include "edit_line.h"
#include "string.h"


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
  return (history);
}

int	read_cmds(t_info *info)
{
  char			*str;
  t_history		*history;
  
  history = ctrlcget(&info, NULL);
  my_putstr(info->termcaps.invi_cursor, 1);
  configure_signals();
  while ((str = usr_cmd(0, history, info->termcaps)))
    {
      my_put_in_history(&history, str);
      history = ctrlcget(&info, history);
      /* fonction de parseur d'exec toussa² ici*/
    }
  free_history(history);
  my_putstr(info->termcaps.visi_cursor, 1);
  return (0);
}
