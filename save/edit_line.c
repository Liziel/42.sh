/*
** edit_line.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 14:36:25 2013 pierre-yves thomas
** Last update Fri May 10 12:15:11 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "lib.h"

int		init_values(int *history_pl, int *reverse_case,
			    char **str, char **cmd)
{
  *history_pl = 0;
  *reverse_case = 0;
  if (((*str) = malloc(sizeof(**str) * 5)) == NULL ||
      ((*cmd) = malloc(sizeof(**cmd) * 2)) == NULL)
    {
      if ((*str) != NULL)
	free(*str);
      return (-1);
    }
  (*str) = memset((*str), 0, 5);
  (*cmd) = memset((*cmd), 0, 2);
  return (0);
}

char		*usr_cmd(int fd, t_options options)
{
  char		*str;
  char		*cmd;
  int		reverse_case;
  int		history_pl;

  if (init_values(&history_pl, &reverse_case, &str, &cmd) == -1)
    return (NULL);
  show_cmd(str[0], cmd, reverse_case, options);
  while (str[0] != 10 || str[1] != 0 || str[2] != 0)
    {
      str = memset(str, 0, 5);
      if (read(fd, str, 4) <= 0 || str[0] == 4)
	return (NULL);
      modif_cmd(&cmd, str, &reverse_case, options);
      show_cmd(str[0], cmd, reverse_case, options);
    }
  my_putstr(1, "\n");
  free(str);
  return (cmd);
}
