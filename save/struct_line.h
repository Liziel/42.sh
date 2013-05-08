/*
** struct.h for 42 in /home/thomas_1//Projets/42sh
** 
** Made by pierre-yves thomas
** Login   <thomas_1@epitech.net>
** 
** Started on  Mon Apr 22 17:12:14 2013 pierre-yves thomas
** Last update Tue May  7 11:10:03 2013 pierre-yves thomas
*/

#ifndef STRUCT_
# define STRUCT_

typedef struct s_options
{
  char  *clear;
  char  *clean_end;
  char  *reverse;
  char  *forward;
  char  *cursor;
  char  *go2;
  char	*save_pos_cursor;
  char	*restore_to_pos_cursor;
  char  *invi_cursor;
  char  *visi_cursor;
}t_options;

typedef struct s_list
{
  char		*str;
  struct s_list	*next;
  struct s_list	*prev;
}t_list;

#endif
