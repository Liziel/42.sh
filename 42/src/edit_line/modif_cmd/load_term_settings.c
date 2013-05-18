/*
** load_term_settings.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 14:32:24 2013 pierre-yves thomas
** Last update Fri May 17 17:18:26 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include "edit_line.h"
#include "string.h"

void    attribute_options(t_options *options)
{
  options->clear = tgetstr("cl", NULL);
  options->clean_end = tgetstr("cd", NULL);
  options->reverse = tgetstr("mr", NULL);
  options->forward = tgetstr("me", NULL);
  options->cursor = tgetstr("cm", NULL);
  options->invi_cursor = tgetstr("vi", NULL);
  options->visi_cursor = tgetstr("ve", NULL);
  options->up_cursor = tgetstr("up", NULL);
  options->down_cursor = tgetstr("do", NULL);
  retain_struct_options(1, options);
}

int     modify_terminal(struct termios *opt)
{
  opt->c_lflag &= ~ICANON;
  opt->c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, opt) == -1)
    return (1);
  return (0);
}

int	load_tgets_funcs(struct termios *opt)
{
  if (tcgetattr(0, opt) == -1)
    {
      my_putstr("Fail on tcgetattr", 2);
      return (-1);
    }
  if (tgetent(NULL, NULL) != 1)
    {
      my_putstr("Fail on tgetent", 2);
      return (-1);
    }
  return (0);
}