/*
** exec.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 13 14:54:51 2013 vincent colliot
** Last update Mon May 13 15:45:33 2013 vincent colliot
*/

#ifndef EXEC_H_
# define EXEC_H_

# include "edit_line.h"
# include "status.h"

typedef struct s_info{
  //FD		tty?
  t_options	termcaps;
  STATUS	st;
}		t_info;

	/* exec.c */
BOOL	exec_cmd(t_cmd*, t_info*, BOOL, FD[3]);
BOOL	calque_redir(t_redir*, FD[3], t_info*);

#endif
