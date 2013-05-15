/*
** read_cmds.c for 42 in /home/thomas_1//Projets/42.sh/42/src/edit_line
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Wed May 15 17:14:07 2013 pierre-yves thomas
** Last update Wed May 15 18:35:18 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include "edit_line.h"
#include "string.h"

int	read_cmds(t_info info)
{
  char			*str;
  t_history		*history;
  struct termios        opt;
  
  history = NULL;
  if (load_tgets_funcs(&opt) == -1)
    return (-1);
  modify_terminal(&opt);
  my_putstr(info.termcaps.invi_cursor, 1);
  configure_signals();
  while ((str = usr_cmd(history, info.termcaps)))
    {
      my_put_in_history(&history, str);
      retain_history(1, &history);
      /* fonction de parseur d'exec toussa² ici*/
      free(str);
    }
  free_history(history);
  my_putstr(info.termcaps.visi_cursor, 1);
  return (0);
}
