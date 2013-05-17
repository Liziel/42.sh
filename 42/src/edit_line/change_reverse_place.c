/*
** change_reverse_place.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Thu May  9 11:30:50 2013 pierre-yves thomas
** Last update Fri May 17 17:36:43 2013 pierre-yves thomas
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"
#include "edit_line.h"

void	delete_first_word_met(int *rev_c, char **cmd)
{
  char	*save;
  int	i;
  int	save_rev_c;
  int	len;

  len = my_strlen(*cmd) - 1;
  i = (*rev_c);
  while (i < len && ((*cmd)[i] == ' ' || (*cmd)[i] == '\t'))
    i++;
  while (i < len && ((*cmd)[i] != ' ' && (*cmd)[i] != '\t'))
    i++;
  if (i != len)
    i--;
  save_rev_c = (*rev_c) + 1;
  save = my_strndup((*cmd) + save_rev_c - 1, i + 2 - save_rev_c);
  remind_save_str(1, &save);
  free(save);
  while (save_rev_c < i + 2)
    {
      del_letter_in_str(0, &save_rev_c, cmd);
      save_rev_c = (*rev_c) + 1;
      i--;
    }
}

void            reverse_to_begin(char value, int *reverse_case, char **cmd)
{
  (void)value;
  (void)cmd;
  (*reverse_case) = 0;
}

void            reverse_to_end(char value, int *reverse_case, char **cmd)
{
  (void)value;
  (*reverse_case) = my_strlen(*cmd);
}

static	int	fill_fct_ptr(void (***options)(int *, char **))
{
  int           nb;

  nb = -1;
  if (((*options) = malloc(sizeof(*options) * 6)) == NULL)
    return (-1);
  while (++nb < 6)
    if (((*options)[nb] = malloc(sizeof(**options))) == NULL)
      return (-1);
  (*options)[0] = move_to_prev_word;
  (*options)[1] = delete_first_word_met;
  (*options)[2] = move_to_next_word;
  (*options)[3] = uppercase_first_letter_found;
  (*options)[4] = lowercase_letters_found;
  (*options)[5] = NULL;
  return (0);
}

void		move_reverse_case(char value, int *rev_c, char **cmd)
{
  void		(**options)(int *, char **);
  static char	opt[6] = {98, 100, 102, 99, 108};
  int		len;
  int		i;

  i = -1;
  len = my_strlen(*cmd);
  if (fill_fct_ptr(&options) == -1)
    return ;
  while (++i < 6 && opt[i] != value);
  if (i != 6)
    options[i](rev_c, cmd);
  else if ((value == 68 || value == 2) && (*rev_c) > 0)
    (*rev_c)--;
  else if ((value == 67 || value == 6) && (*rev_c) < len)
    (*rev_c)++;
  free(options);
}
