/*
** fill_dir.c for 42 in /home/thomas_1//Projets/42sh/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon Apr 29 17:37:50 2013 pierre-yves thomas
** Last update Mon May 13 16:50:23 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"

/*
** nb = 1 on prends le char * par l'adress (pas besoin de free *str par la suite)
** nb = 2 sauvegarde par strdup (free + strdup)
** la sauvegarde aura lieu lors d'un cd et au début du programme.
*/

void    retain_dir(int nb, char **str)
{
  static char *dir = NULL;

  if (nb == 1)
    *str = dir;
  else if (nb == 2)
    {
      if (dir != NULL)
	free(dir);
      dir = strdup(*str);
    }
}

void	fill_dir(t_list *env)
{
  char	*dir;

  dir = take_str_from_env("PWD=", env);
  retain_dir(2, &dir);
  free(dir);
}
