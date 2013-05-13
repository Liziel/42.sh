/*
** edit_line.c for 42 in /home/thomas_1//Projets/42sh
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Fri Apr 26 14:36:25 2013 pierre-yves thomas
** Last update Mon May 13 14:52:28 2013 vincent colliot
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "edit_line.h"

static char     *free_str_edit_lines(char *s1, char *s2, int *rev_c)
{
  if (s1 != NULL)
    free(s1);
  if (s2 != NULL)
    free(s2);
  if (rev_c != NULL)
    free(rev_c);
  return (NULL);
}

int		init_values(int *history_pl, int **rev_c,
			    char **str, char **cmd)
{
  *history_pl = 0;
  if (((*str) = malloc(sizeof(**str) * 5)) == NULL ||
      ((*cmd) = malloc(sizeof(**cmd) * 2)) == NULL ||
      ((*rev_c) = malloc(sizeof(**rev_c) * 2)) == NULL)
    {
      if ((*str) != NULL)
	free(*str);
      return (-1);
    }
  (*str) = memset((*str), 0, 5);
  (*cmd) = memset((*cmd), 0, 2);
  (*rev_c)[0] = 0;
  return (0);
}

char		*usr_cmd(int fd, t_options options)
{
  char		*str;
  char		*cmd;
  int		*reverse_case;
  int		history_pl;

  if (init_values(&history_pl, &reverse_case, &str, &cmd) == -1)
    return (free_str_edit_lines(str, cmd, reverse_case));
  reverse_case[1] = fd;
  show_cmd(str[0], cmd, reverse_case, options);
  while (str[0] != 10 || str[1] != 0 || str[2] != 0)
    {
      str = memset(str, 0, 5);
      if (read(fd, str, 4) <= 0 || str[0] == 4)
	return (free_str_edit_lines(cmd, str, reverse_case));
      modif_cmd(&cmd, str, &reverse_case[0], options);
      show_cmd(str[0], cmd, reverse_case, options);
    }
  my_putstr(1, "\n");
  free_str_edit_lines(str, NULL, reverse_case);
  return (cmd);
}
