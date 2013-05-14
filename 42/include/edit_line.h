/*
** edit_line.h for 42 in /home/thomas_1//Projets/42.sh/42/include
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Mon May 13 13:04:25 2013 pierre-yves thomas
** Last update Tue May 14 02:09:20 2013 vincent colliot
*/

#ifndef	EDIT_LINE_H
# define EDIT_LINE_H

# include <term.h>

typedef struct	s_options{
  char		*clear;
  char		*clean_end;
  char		*reverse;
  char		*forward;
  char		*cursor;
  char		*go2;
  char		*invi_cursor;
  char		*visi_cursor;
}		t_options;

/*
** edit_line.c
*/
char            *usr_cmd(int, t_options);
int             init_values(int *, int **, char **, char **);

/*
** load_term_settings.c
*/
void    attribute_options(t_options *);
int     modify_terminal(struct termios *);
int     load_tgets_funcs(struct termios *);

/*
** modify_line.c
*/
void    move_reverse_case(char, int *, char *);
void    add_letter_in_str(char, char **, int *);
void    del_letter_in_str(int *, char **);
void	modif_cmd(char **, char *, int *, t_options);

/*
** show_cmd.c
*/
void                    show_cmd(char, char *, int *, t_options);

#endif
