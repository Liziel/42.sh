/*
** show_cmd.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon May  6 17:57:14 2013 pierre-yves thomas
** Last update Wed May 15 16:34:59 2013 pierre-yves thomas
*/

#include <sys/ioctl.h>
#include "lib.h"
#include "struct.h"

void			show_cmd(char key, char *cmd,
				 int reverse_case, t_options options)
{
  int			i;
  int			count;
  struct winsize	ws;

  ioctl(0, TIOCGWINSZ, &ws);
  i = -1;
  count = 0;
  if (key != 10)
    my_putstr(1, options.clean_end);
  while (cmd[++i] != '\0')
    {
      if (key != 10 && i == reverse_case && cmd[i] != '\t')
        my_putstr(1, options.reverse);
      my_putchar(1, cmd[i]);
      my_putstr(1, options.forward);
      if (i != 0 && i % (ws.ws_col) == 0)
	count++;
    }
  if (i == reverse_case && key != 10)
    my_putstr(1, options.reverse);
  if (i != 0 && i % (ws.ws_col) == 0)
    count++;
  my_putchar(1, ' ');
  my_putstr(1, options.forward);
  while ((--count) / 2 >= 0)
    my_putstr(1, options.up_cursor);
  my_putstr(1, options.down_cursor);
  my_putstr(1, "\r");
}
