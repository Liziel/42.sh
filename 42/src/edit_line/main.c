/*
** main.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon Apr 22 14:22:14 2013 pierre-yves thomas
** Last update Fri May 17 18:49:29 2013 pierre-yves thomas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "termcap.h"
#include "lib.h"
#include "shell.h"

int			main(int ac, char **av, char **environement)
{
  t_list		*history;
  t_list		*env;
  char			*str;
  struct termios        opt;
  t_options             options;

  history = NULL;
  if (load_tgets_funcs(&opt) == -1)
    return (-1);
  split_tab_in_list(&env, environement);
  modify_terminal(&opt);
  attribute_options(&options);
  fill_dir(env);
  my_putstr(1, options.invi_cursor);
  configure_signals();
  show_prompt();
  while ((str = usr_cmd(history, options)) != NULL)
    {
      go_down_of_cmd_high(str, options);
      show_prompt();
      my_put_in_list(&history, str);
      retain_list(1, &history);
      free(str);
    }
  free_list(history);
  free_list(env);
  my_putstr(1, options.visi_cursor);
  return (0);
}
