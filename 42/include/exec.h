/*
** exec.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 13 14:54:51 2013 vincent colliot
<<<<<<< HEAD
** Last update Sat May 18 17:12:41 2013 vincent colliot
=======
** Last update Wed May 15 18:32:03 2013 pierre-yves thomas
>>>>>>> 17eee20bcf22af4a3d760ac1186819eec227d729
*/

#ifndef EXEC_H_
# define EXEC_H_

# include "edit_line.h"
# include "status.h"
# include "bool.h"
# include "alias.h"

typedef struct s_info
{
  struct s_options	termcaps;
  STATUS		st;
  t_alias		*alias;
}			t_info;

	/* exec.c */
BOOL	exec_cmd(t_cmd*, t_info*, FLAG, FD[3]);

	/* redir.c */
BOOL	calque_redir(t_redir*, FD[3], FD[3], t_info*);
BOOL	rdleft(t_redir*, FD[3], t_info*);

	/* exec_form */
STATUS		exec_form(t_words*, BOOL*, BOOL);

	/* pré_exec */
BOOL	pre_exec(t_jobs*, t_info*);

#endif
