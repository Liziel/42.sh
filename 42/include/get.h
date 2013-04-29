/*
** get.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 21:17:09 2013 vincent colliot
** Last update Mon Apr 29 21:41:43 2013 vincent colliot
*/

#ifndef GET_H_
# define GET_H_

typedef struct s_get{
  char	*word;
  struct s_get	*next;
  struct s_get  *prev;
}		t_get;

#endif
