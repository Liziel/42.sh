/*
** edit_line.h for 42 in /home/thomas_1//Projets/42.sh/42/include
**
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
**
** Started on  Mon May 13 13:04:25 2013 pierre-yves thomas
** Last update Tue May 21 16:18:20 2013 vincent colliot
*/

#ifndef	EDIT_LINE_H
# define EDIT_LINE_H

# include <term.h>
# include "flag.h"
# include "history.h"

typedef struct	s_options
{
  char		*clear;
  char		*clean_end;
  char		*reverse;
  char		*forward;
  char		*cursor;
  char		*go2;
  char		*invi_cursor;
  char		*visi_cursor;
  char		*up_cursor;
  char		*down_cursor;
}		t_options;

# include "lexec.h"
# include "exec.h"

/*
** change_reverse_place.c
*/
void            reverse_to_begin(char, int *, char **);
void            reverse_to_end(char, int *, char **);

/*
** clean_screen.c
*/
void    clean_screen(char, int *, char **);
void    clean_str(char, int *, char **);

/*
** configure_signals.c
*/
void    configure_signals();
void	go_down_of_cmd_high(char *, t_options);

/*
** edit_line.c
*/
char	*usr_cmd(int, t_history *, t_options);
int	init_values(int *, int *, char **, char **);

/*
** load_term_settings.c
*/
void    attribute_options(t_options *);
int     modify_terminal(struct termios *);
int     load_tgets_funcs();
int     init_termios(struct termios *, struct termios *);
char    *unset_termios(struct termios *);

/*
** modify_line.c
*/
void    move_reverse_case(char, int *, char **);
void    del_letter_in_str(char, int *, char **);
int	add_letter_in_str(char, int *, char **);
int	modif_cmd(char **, char *, int *);

/*
** move_to_word_fct.
*/
void    move_to_prev_word(int *, char **);
void    move_to_next_word(int *, char **);

/*
** remain_datas.c
*/
void	retain_struct_options(int, t_options *);
void	retain_cmd(int, char **);
void	retain_reverse_case(int, int *);

/*
** read_cmds.c
*/
//int     read_cmds(t_info *);

/*
** save_and_copy_part_str.c
*/
void	remind_save_str(int, char **);
void    del_after_cursor(char, int *, char **);
void    del_before_cursor(char, int *, char **);
void    copy_part_str(char, int *, char **);

/*
** show_cmd.c
*/
void	show_cmd(char, int, char *, int);

/*
** swap_chars_on_cmd.c
*/
void    swap_chars_on_cmd(char, int *, char **);

/*
** take_cmd_from_history.c
*/
int	take_cmd_from_history(int, int *, char **, t_history *);

/*
** upper_lower_case_letter.c
*/
void    lowercase_letters_found(int *, char **);
void    uppercase_first_letter_found(int *, char **);

#endif
