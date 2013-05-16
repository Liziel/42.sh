/*
** aff_prompt.c for 42 in /home/thomas_1//Projets/42sh/42sh-2017-cloare_q/src
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Sat Apr 27 13:25:37 2013 pierre-yves thomas
** Last update Fri May 10 13:05:19 2013 pierre-yves thomas
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

void            having_time(int *hour, int *min)
{
  time_t        seconds;
  struct tm     *actual_time;

  if (time(&seconds) != -1 && (actual_time = localtime(&seconds)) != NULL)
    {
      *hour = actual_time->tm_hour;
      *min = actual_time->tm_min;
    }
  else
    {
      *hour = -1;
      *min = -1;
    }
}

void	show_prompt()
{
  char	*dir;
  int	hour;
  int	min;

  having_time(&hour, &min);
  retain_dir(1, &dir);
  printf("([%d : %d] %s)\n", hour, min, dir);
}
