/*
** show_cmd.c for 42 in /home/thomas_1//Projets/42sh
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Mon May  6 17:57:14 2013 pierre-yves thomas
** Last update Tue May 14 01:01:49 2013 vincent colliot
*/

#include <unistd.h>
#include <string.h>
#include "edit_line.h"

static void	my_putchar(int fd, char a)
{
  write(fd, &a, 1);
}

void	show_cmd(char key, char *cmd, int *rev_c, t_options options)
{
  int	i;

  i = -1;
  my_putstr("\r>", 1);
  if (key != 10)
    my_putstr(options.clean_end, rev_c[1]);
  while (cmd[++i] != '\0')
    {
      if (key != 10 && i == rev_c[0] && cmd[i] != '\t')
        my_putstr(options.reverse, rev_c[1]);
      my_putchar(cmd[i], rev_c[1]);
      my_putstr(options.forward, rev_c[1]);
    }
  if (i == rev_c[0])
    {
      if (key != 10)
        my_putstr(options.reverse, rev_c[1]);
      my_putchar(rev_c[1], ' ');
      my_putstr(options.forward, rev_c[1]);
    }
}
