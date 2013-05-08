/*
** env.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May  8 23:54:49 2013 vincent colliot
** Last update Thu May  9 00:00:42 2013 vincent colliot
*/

#ifndef ENV_H_
# define ENV_H_

#include <unistd.h>

extern char **environ;

/* env */
char	*get_env(char*);

/* folder env' */
BOOL	in_directory(char*, char*);

#endif
