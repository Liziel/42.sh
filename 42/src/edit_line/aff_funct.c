/*
** aff_funct.c for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Fri Apr 26 14:29:55 2013 pierre-yves thomas
** Last update Sat Apr 27 13:09:04 2013 pierre-yves thomas
*/

#include <unistd.h>

void    my_putchar(int fd, char a)
{
  write(fd, &a, 1);
}

void    my_putstr(int fd, char *str)
{
  int   i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(fd, str[i]);
}
