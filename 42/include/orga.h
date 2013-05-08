/*
** orga.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May  8 23:28:36 2013 vincent colliot
** Last update Thu May  9 01:04:43 2013 vincent colliot
*/

#ifndef ORGA_H_
# define ORGA_H_

#include "lexec.h"

/* prim'orga */
t_jobs  *orga(t_get*, char**, BOOL*);

/* jobs */
t_jobs *get_jobs(t_get*, t_jobs*, char**);

/* exec */
t_exec *get_exec(t_get*, t_exec*, char**);

/* pipe */
BOOL	get_pipe(t_exec*, char**);

/* cmd */
BOOL	get_cmd(t_pipes*, char**);
BOOL	cmd_part(t_get*, t_get**, t_cmd*, char**);
t_words	*interpret_cmd(t_get*, t_get**, char**, t_words**);
t_words	*interpret_params(t_get*, t_get**, char**, t_words**);

/* help */
BOOL    lvl_parents(t_get**, char**);
BOOL	match_them(char*, char*, t_words**, BOOL*);

/* nullify */
BOOL	nullify_exec(t_exec*);
BOOL	nullify_pipes(t_pipes*);

#endif
