/*
** built.c for 42 in /home/lecorr_b//projets/42sh/42.sh/42/include
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May  3 17:56:39 2013 thomas lecorre
** Last update Sun May 12 22:13:01 2013 vincent colliot
*/

#ifndef	BUILT_H__
#define BUILT_H__

#include "lexec.h"

typedef struct s_call
{
  char	*name;
  int	(*ptr)(t_words *, void *);
} t_call;

char	*my_strdup(char *);

int	echo(t_words *, void *);
int	setenv(t_words *, void *);


#endif
