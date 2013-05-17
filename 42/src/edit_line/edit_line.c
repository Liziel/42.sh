/*
** edit_line.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 14:36:25 2013 pierre-yves thomas
** Last update Fri May 17 19:19:29 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <unistd.h>
#include "edit_line.h"
#include "string.h"

static char	*free_str_edit_lines(char *s1, char *s2)
{
  if (s1 != NULL)
    free(s1);
  if (s2 != NULL)
    free(s2);
  s1 = NULL;
  remind_save_str(1, &s1);
  return (NULL);
}

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
  (*str) = my_memset((*str), 0, 5);
  (*cmd) = my_memset((*cmd), 0, 2);
  return (0);
}

char		*usr_cmd(int fd, t_history *history, t_options options)
{
  char		*str;
  char		*cmd;
  int		reverse_case;
  int		history_pl;

  if (init_values(&history_pl, &reverse_case, &str, &cmd) == -1)
    return (NULL);
  show_cmd(str[0], fd, cmd, reverse_case);
  while (str[0] != 10 || str[1] != 0 || str[2] != 0)
    {
      retain_cmd(1, &cmd);
      str = my_memset(str, 0, 5);
      retain_reverse_case(1, &reverse_case);
      if (read(fd, str, 4) <= 0 || str[0] == 4)
	return (free_str_edit_lines(str, cmd));
      retain_reverse_case(2, &reverse_case);
      modif_cmd(&cmd, str, &reverse_case);
      if (history_pl < length_of_history(history) && str[0] == 27 && str[2] == 65)
	take_cmd_from_history(++history_pl, &reverse_case, &cmd, history);
      else if (history_pl > 0 && str[0] == 27 && str[2] == 66)
	take_cmd_from_history(--history_pl, &reverse_case, &cmd, history);
      show_cmd(str[0], fd, cmd, reverse_case);
    }
  my_putstr("\n", 1);
  free_str_edit_lines(str, NULL);
  return (cmd);
}
