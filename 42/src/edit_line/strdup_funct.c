/*
** strdup_funct.c for 42sh in /home/thomas_1//Projets/42sh/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon May  6 17:35:13 2013 pierre-yves thomas
** Last update Mon May  6 17:35:38 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <string.h>

char            *my_strndup(char *str, int len)
{
  char          *mem;
  int           i;

  if ((mem = malloc(sizeof(*mem) * (len + 1))) == NULL)
    return (NULL);
  mem = memset(mem, 0, len + 1);
  i = -1;
  while (++i < len && str[i] != '\0')
    mem[i] = str[i];
  return (mem);
}
