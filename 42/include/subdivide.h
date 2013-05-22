/*
** subdivide.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 21:50:16 2013 vincent colliot
** Last update Wed May 22 06:15:48 2013 vincent colliot
*/

#ifndef SUBDIVIDE_H_
# define SUBDIBIDE_H_

#include "alias.h"
#include "exec.h"

t_get	*subdivide(char *s, t_get *prev, char **bad_sintax);
t_get	*comment(t_get *w, t_get *prev);
BOOL	seed_alias(char*, t_alias*, char**);
BOOL	grow_var(char *, char **, size_t, t_info*);

#endif
