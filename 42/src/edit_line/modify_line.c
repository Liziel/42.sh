/*
** modify_line.c for 42sh in /home/thomas_1//Projets/42sh/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon May  6 17:44:08 2013 pierre-yves thomas
** Last update Mon May 13 15:20:02 2013 pierre-yves thomas
*/

#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "shell.h"

void    add_letter_in_str(char value, char **cmd, int *reverse_case)
{
  int   len;

  len = strlen(*cmd) + 1;
  while (--len > (*reverse_case))
    (*cmd)[len + 1] = (*cmd)[len];
  if (strlen(*cmd) + 1 > 1)
    (*cmd)[len + 1] = (*cmd)[len];
  (*cmd)[len] = value;
  (*reverse_case)++;
  if (((*cmd) = realloc(*cmd, strlen(*cmd) + 2)) != NULL)
    (*cmd)[strlen(*cmd) + 1] = '\0';
}

void    del_letter_in_str(char value, int *reverse_case, char **cmd)
{
  int   suppr;

  (void)value;
  suppr = (*reverse_case) - 1;
  if ((*reverse_case) > 0)
    {
      while ((*cmd)[suppr] != '\0')
        {
          (*cmd)[suppr] = (*cmd)[suppr + 1];
          suppr++;
        }
      my_putstr(1, "\r");
      (*reverse_case)--;
    }
}

/*
** 65 cmd + anciennes / 66 cmd + recentes (str[0] = 27, str[2])
*/

static int	fill_fct_ptr(void (***options)(char, int *, char **))
{
  int		nb;

  nb = -1;
  if (((*options) = malloc(sizeof(*options) * 14)) == NULL)
    return (-1);
  while (++nb < 13)
    if (((*options)[nb] = malloc(sizeof(**options))) == NULL)
      return (-1);
  (*options)[0] = move_reverse_case;
  (*options)[1] = del_letter_in_str;
  (*options)[2] = clean_screen;
  (*options)[3] = reverse_to_begin;
  (*options)[4] = reverse_to_end;
  (*options)[5] = del_after_cursor;
  (*options)[6] = copy_part_str;
  (*options)[7] = clean_str;
  (*options)[8] = move_reverse_case;
  (*options)[9] = move_reverse_case;
  (*options)[10] = del_before_cursor;
  (*options)[11] = swap_chars_on_cmd;
  (*options)[12] = del_letter_in_str;
  (*options)[13] = NULL;
  return (0);
}

void            modif_cmd(char **cmd, char *str, int *reverse_case)
{
  int		i;
  void		(**options)(char, int *, char **);
  static char  	opt[13] = {27, 127, 12, 1, 5, 11, 25, 21, 2, 6, 23, 20, 8};

  i = -1;
  if (fill_fct_ptr(&options) == -1)
    return ;
  while (++i < 13 && opt[i] != str[0]);
  if (i != 13)
    if (i == 0 && str[2] == 0)
      (options[i])(str[1], reverse_case, cmd);
    else if (i == 8 || i == 9)
      (options[i])(str[0], reverse_case, cmd);
    else
      (options[i])(str[2], reverse_case, cmd);
  else
    {
      i = -1;
      while (++i < 4 && str[i] != 0 && str[i] != 10 && str[i] != 27)
	add_letter_in_str(str[i], cmd, reverse_case);
    }
  free(options);
}
