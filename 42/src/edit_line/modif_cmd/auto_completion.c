/*
** auto_completion.c for 42 in /home/thomas_1//Projets/42.sh/42/src/edit_line/modif_cmd
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Sun May 26 11:09:19 2013 pierre-yves thomas
** Last update Sun May 26 11:35:06 2013 vincent colliot
*/

#include <stdio.h>
#include "string.h"
#include "edit_line.h"

void	auto_completion(char value, int *rev_c, char **cmd)
{
  char  *dir;
  char	*s;

  (void)value;
  s = my_strndup(*cmd + lastoccur_bf(*cmd, ' ', *rev_c), *rev_c -
		 lastoccur_bf(*cmd, ' ', *rev_c));
  dir = my_strndup(s, lastoccur_bf(s, '/', my_strlen(s)) +
		   IN('/', s));
  printf("\n");

  prompt(TRUE);
}

