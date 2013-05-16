/*
** load_term_settings.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 14:32:24 2013 pierre-yves thomas
** Last update Wed May 15 12:00:33 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include "termcap.h"
#include "lib.h"

void			retain_struct_options(int opt, t_options *options)
{
  static t_options	save_opt;

  if (opt == 1)
    save_opt = (*options);
  else
    (*options) = save_opt;
}

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
      my_putstr(2, "Fail on tcgetattr");
      return (-1);
    }
  if (tgetent(NULL, NULL) != 1)
    {
      my_putstr(2, "Fail on tgetent");
      return (-1);
    }
  return (0);
}
