/*
** show_cmd.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon May  6 17:57:14 2013 pierre-yves thomas
** Last update Mon May 13 13:41:01 2013 pierre-yves thomas
*/

#include <unistd.h>
#include <string.h>
#include "edit_line.h"

static void	my_putstr(int fd, char a)
{
  write(fd, &a, 1);
}

static void	my_putstr(int fd, char *str)
{
  write(fd, str, strlen(str));
}

void	show_cmd(char key, char *cmd, int *rev_c, t_options options)
{
  int	i;

  i = -1;
  my_putstr(1, "\r");
  if (key != 10)
    my_putstr(rev_c[1], options.clean_end);
  while (cmd[++i] != '\0')
    {
      if (key != 10 && i == rev_c[0] && cmd[i] != '\t')
        my_putstr(rev_c[1], options.reverse);
      my_putchar(rev_c[1], cmd[i]);
      my_putstr(rev_c[1], options.forward);
    }
  if (i == rev_c[0])
    {
      if (key != 10)
        my_putstr(rev_c[1], options.reverse);
      my_putchar(rev_c[1], ' ');
      my_putstr(rev_c[1], options.forward);
    }
}
