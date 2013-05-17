/*
** t_list_funct.c for 42 in /home/thomas_1//Projets/42sh/42sh-2017-cloare_q/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 15:37:17 2013 pierre-yves thomas
** Last update Mon May 13 11:08:49 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

void		retain_list(int opt, t_list **list)
{
  static t_list	*save = NULL;

  if (opt == 1)
    save = (*list);
  else
    (*list) = save;
}

void            my_put_in_list(t_list **list, char *str)
{
  t_list        *tmp;

  tmp = malloc(sizeof(*tmp));
  if (tmp != NULL)
    {
      tmp->str = strdup(str);
      tmp->next = (*list);
      if (*list != NULL)
        (*list)->prev = tmp;
      (*list) = tmp;
    }
}

void            my_show_list(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      printf("%s", tmp->str);
      if (tmp->next != NULL)
        printf(" -> ");
      tmp = tmp->next;
    }
  printf("\n");
}

int		length_of_list(t_list *list)
{
  int		len;
  t_list       	*tmp;

  len = 0;
  tmp = list;
  while (tmp != NULL)
    {
      len++;
      tmp = tmp->next;
    }
  return (len);
}

void		free_list(t_list *list)
{
  t_list	*tmp;
  t_list	*after;

  tmp = list;
  after = list;
  while (tmp != NULL)
    {
      after = after->next;
      free(tmp->str);
      free(tmp);
      tmp = after;
    }
}
