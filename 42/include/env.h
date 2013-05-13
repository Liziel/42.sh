/*
** env.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May  8 23:54:49 2013 vincent colliot
** Last update Mon May 13 15:45:24 2013 vincent colliot
*/

#ifndef ENV_H_
# define ENV_H_

# include <unistd.h>
# include "bool.h"

extern char **environ;

/* env */
char	*get_env(char*);

/* folder env' */
BOOL	in_directory(char*, char*);

#endif
