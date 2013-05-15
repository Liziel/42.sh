/*
** configure_signals.c for 42 in /home/thomas_1//Projets/42sh/42sh-2017-cloare_q/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 18:01:08 2013 pierre-yves thomas
** Last update Wed May 15 16:55:29 2013 pierre-yves thomas
*/

#include <signal.h>
#include <sys/ioctl.h>
#include <string.h>
#include "shell.h"
#include "lib.h"

void		retain_cmd(int opt, char **cmd)
{
  static char  	*save = NULL;

  if (opt == 1)
    save = (*cmd);
  else if (opt == 2)
    (*cmd) = save;
}

void			go_down_of_cmd_high(char *cmd, t_options opt)
{
  int			high;
  struct winsize	ws;

  ioctl(0, TIOCGWINSZ, &ws);
  high = strlen(cmd) / ws.ws_col;
  while (--high >= 0)
    my_putstr(1, opt.down_cursor);
}

void	catch_signal(int num)
{
  char		*save_cmd;
  t_options	tmp;

  retain_struct_options(2, &tmp);
  retain_cmd(2, &save_cmd);
  if (num == SIGINT)
    {
      my_putstr(1, "\n");
      go_down_of_cmd_high(save_cmd, tmp);
      show_prompt();
      save_cmd = memset(save_cmd, 0, strlen(save_cmd));
    }
}

void	configure_signals()
{
  signal(SIGINT, catch_signal);
}
