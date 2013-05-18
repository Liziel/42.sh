/*
** alias.h for  in /home/collio_v/rendu_svn/42.sh/42/src
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May 18 01:17:38 2013 vincent colliot
** Last update Sat May 18 01:18:54 2013 vincent colliot
*/

#ifndef ALIAS_H_
# define ALIAS_H_

typedef struct s_alias{
  char	*name;
  char	*fill;
  struct s_alias *next;
  size_t	n;
}			t_alias;

#endif
