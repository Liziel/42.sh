/*
** split_funct.c for 42 in /home/thomas_1//Projets/42sh/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon Apr 29 17:53:30 2013 pierre-yves thomas
** Last update Mon Apr 29 17:54:03 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include "lib.h"

void    split_tab_in_list(t_list **list, char **tabl)
{
  int   i;

  i = -1;
  (*list) = NULL;
  while (tabl != NULL && tabl[++i] != NULL)
    my_put_in_list(list, tabl[i]);
}
