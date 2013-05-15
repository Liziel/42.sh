/*
** take_str_from_env.c for 42 in /home/thomas_1//Projets/42sh/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon Apr 29 14:40:13 2013 pierre-yves thomas
** Last update Mon Apr 29 15:18:29 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "lib.h"

char		*take_str_after_required(int len, char *str)
{
  char		*mem;
  int		len_str;
  int		i;

  len_str = strlen(str);
  if ((mem = malloc(sizeof(*mem) * (len_str - len + 1))) == NULL)
    {
      my_putstr(2, "Warning : Can't perform malloc, returning NULL\n");
      return (NULL);
    }
  i = -1;
  mem = memset(mem, 0, len_str - len + 1);
  len--;
  while (str[len] != '\0')
    mem[++i] = str[++len];
  return (mem);
}

char		*take_str_from_env(char *request, t_list *env)
{
  t_list	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      if (strncmp(tmp->str, request, strlen(request)) == 0)
	return (take_str_after_required(strlen(request), tmp->str));
      tmp = tmp->next;
    }
  return (NULL);
}
