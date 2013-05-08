/*
** modify_line.c for 42sh in /home/thomas_1//Projets/42sh/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon May  6 17:44:08 2013 pierre-yves thomas
** Last update Wed May  8 16:23:52 2013 pierre-yves thomas
*/

#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "shell.h"

void    move_reverse_case(char value, int *reverse_case, char *cmd)
{
  int   len;

  len = strlen(cmd) - 1;
  if (value == 68 && (*reverse_case) > 0)
    (*reverse_case)--;
  else if (value == 67 && (*reverse_case) <= len)
    (*reverse_case)++;
}


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

void    del_letter_in_str(int *reverse_case, char **cmd)
{
  int   suppr;

  suppr = (*reverse_case) - 1;
  if ((*reverse_case) > 0)
    {
      while ((*cmd)[suppr] != '\0')
        {
          (*cmd)[suppr] = (*cmd)[suppr + 1];
          suppr++;
        }
      (*reverse_case)--;
    }
}

void            modif_cmd(char **cmd, char *str,
                          int *reverse_case, t_options options)
{
  int		i;

  i = -1;
  if (str[0] == 27 && (str[2] == 68 || str[2] == 67))
    move_reverse_case(str[2], reverse_case, *cmd);
  else if (str[0] == 127 && str[1] == 0)
    del_letter_in_str(reverse_case, cmd);
  else if (str[0] == 12)
    {
      my_putstr(1, options.clear);
      show_prompt();
    }
  else if (str[0] == 1)
    (*reverse_case) = 0;
  else if (str[0] == 5)
    (*reverse_case) = strlen(*cmd);
  while (++i < 4 && str[i] != 0 && str[i] != 10 && str[i] != 27)
    add_letter_in_str(str[i], cmd, reverse_case);
}
