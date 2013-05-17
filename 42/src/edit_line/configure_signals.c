/*
** configure_signals.c for 42 in /home/thomas_1//Projets/42sh/42sh-2017-cloare_q/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 18:01:08 2013 pierre-yves thomas
** Last update Fri May 17 19:52:28 2013 pierre-yves thomas
*/

#include <signal.h>
#include <sys/ioctl.h>
#include <string.h>
#include "edit_line.h"
#include "string.h"

void			go_down_of_cmd_high(char *cmd, t_options opt)
{
  int			high;
  struct winsize	ws;

  ioctl(0, TIOCGWINSZ, &ws);
  high = my_strlen(cmd) / ws.ws_col;
  while (--high >= 0)
    my_putstr(opt.down_cursor, 1);
}

void	catch_signal(int num)
{
  char		*save_cmd;
  t_options	tmp;
  int		rev_c;

  retain_struct_options(2, &tmp);
  retain_cmd(2, &save_cmd);
  if (num == SIGINT)
    {
      rev_c = 0;
      show_cmd(10, 0, save_cmd, rev_c);
      my_putstr("\n", 1);
      go_down_of_cmd_high(save_cmd, tmp);
      /* le prompt sera la */
      //show_prompt();
      my_putstr("Prompt test\n", 1);
      save_cmd = my_memset(save_cmd, 0, my_strlen(save_cmd));
      retain_reverse_case(1, &rev_c);
      show_cmd(0, 10, save_cmd, rev_c);
    }
}

void	configure_signals()
{
  signal(SIGINT, catch_signal);
}