/*
** my_strdup.c for my_strdup in /home/lecorr_b//test/Jour08
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Wed Oct 10 09:33:16 2012 thomas lecorre
** Last update Sun May 12 00:51:51 2013 vincent colliot
*/

#include <stdlib.h>
#include "built.h"

char	*my_strdup(char *src)//ep tu peut inclure mon strdup si tu le souhaite!
{
  char	*dest;
  int	i;

  dest = NULL;
  i = 0;
  while (src[i] != '\0')
    i++;
  if ((dest = xmalloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

