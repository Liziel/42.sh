/*
** built.c for 42 in /home/lecorr_b//projets/42sh/42.sh/42/include
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May  3 17:56:39 2013 thomas lecorre
** Last update Tue May 14 17:53:40 2013 thomas lecorre
*/

#ifndef	BUILT_H__
#define BUILT_H__

# include "lexec.h"

typedef struct s_call
{
  char	*name;
  int	(*ptr)(t_words *, void *);
} t_call;

char	*my_strdup(char *);

int	my_echo(t_words *, void *);
int	setenv(t_words *, void *);
int	unsetenv(t_words *, void *);
int	echo_n(t_words *);
int	echo_e(t_words *);
int	echo_E(t_words *);
int	env_cmd(t_words *, void *);
char	**env_copy();
int	my_exit(t_words *, void *);
char	*put_pwd(char *);
int	just_cd(t_words *);
int	cd(t_words *, void *);
void	init_built(t_call *);
void	*stock_tab(t_call *);
int	builtins(t_words *, void *);

#endif
