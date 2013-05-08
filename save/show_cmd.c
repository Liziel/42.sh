/*
** show_cmd.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon May  6 17:57:14 2013 pierre-yves thomas
** Last update Tue May  7 12:50:43 2013 pierre-yves thomas
*/

#include <sys/ioctl.h>
#include "lib.h"
#include "struct.h"

void			show_cmd(char key, char *cmd,
				 int reverse_case, t_options options)
{
  int			i;

  i = -1;
  my_putstr(1, options.restore_to_pos_cursor);
  my_putstr(1, "\r");
  if (key != 10)
    my_putstr(1, options.clean_end);
  while (cmd[++i] != '\0')
    {
      if (key != 10 && i == reverse_case && cmd[i] != '\t')
        my_putstr(1, options.reverse);
      my_putchar(1, cmd[i]);
      my_putstr(1, options.forward);
    }
  if (i == reverse_case)
    {
      if (key != 10)
        my_putstr(1, options.reverse);
      my_putchar(1, ' ');
      my_putstr(1, options.forward);
    }
}
