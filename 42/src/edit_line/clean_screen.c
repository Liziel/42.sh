/*
** clear_screen.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Thu May  9 11:20:06 2013 pierre-yves thomas
** Last update Mon May 13 11:19:25 2013 pierre-yves thomas
*/

#include <string.h>
#include "shell.h"
#include "termcap.h"
#include "lib.h"

void    clean_screen(char value, int *reverse_case, char **cmd)
{
  t_options	tmp;

  retain_struct_options(2, &tmp);
  (void)value;
  (void)reverse_case;
  (void)cmd;
  my_putstr(1, tmp.clear);
  show_prompt();
}

void	clean_str(char value, int *reverse_case, char **cmd)
{
  (void)value;
  my_putstr(1, "\r");
  (*reverse_case) = 0;
  remind_save_str(1, cmd);
  (*cmd) = memset(*cmd, 0, strlen(*cmd));
}
