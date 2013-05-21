/*
** edit_line.c for 42 in /home/thomas_1//Projets/42sh
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Fri Apr 26 14:36:25 2013 pierre-yves thomas
** Last update Mon May 20 23:42:42 2013 pierre-yves thomas
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

static int     	read_cmd(int fd, char **str, char **cmd, int *reverse_case)
{
  retain_cmd(1, cmd);
  (*str) = my_memset((*str), 0, 5);
  retain_reverse_case(1, reverse_case);
  if ((read(fd, (*str), 4) <= 0 || (*str)[0] == 4) && my_strlen(*cmd) == 0)
    {
      free_str_edit_lines((*str), (*cmd));
      return (-1);
    }
  retain_reverse_case(2, reverse_case);
  return (0);
}

char	*finish_usr_cmd(char *cmd, char *str, struct termios unset)
{
  my_putstr("\n", 1);
  unset_termios(&unset);
  free_str_edit_lines(str, NULL);
  return (cmd);
}

char			*usr_cmd(int fd, t_history *history, t_options options)
{
  struct termios	set;
  struct termios	unset;
  char			*str;
  char			*cmd;
  int			reverse_case;
  int			histo_pl;

  prompt();
  if (init_termios(&set, &unset) == -1 ||
      init_values(&histo_pl, &reverse_case, &str, &cmd) == -1)
    return (unset_termios(&unset));
  show_cmd(str[0], fd, cmd, reverse_case);
  while (str[0] != 10 || str[1] != 0 || str[2] != 0)
    {
      if (read_cmd(fd, &str, &cmd, &reverse_case) == -1)
	return (unset_termios(&unset));
      modif_cmd(&cmd, str, &reverse_case);
      if (histo_pl < length_of_history(history) && str[0] == 27 && str[2] == 65)
	take_cmd_from_history(++histo_pl, &reverse_case, &cmd, history);
      else if (histo_pl > 0 && str[0] == 27 && str[2] == 66)
	take_cmd_from_history(--histo_pl, &reverse_case, &cmd, history);
      show_cmd(str[0], fd, cmd, reverse_case);
    }
  return (finish_usr_cmd(cmd, str, unset));
}
