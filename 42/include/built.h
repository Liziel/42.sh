/*
** built.c for 42 in /home/lecorr_b//projets/42sh/42.sh/42/include
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Fri May  3 17:56:39 2013 thomas lecorre
** Last update Sat May 18 23:54:19 2013 vincent colliot
*/

#ifndef	BUILT_H__
#define BUILT_H__

# include "lexec.h"

typedef struct s_call
{
  char	*name;
  int	(*ptr)(t_words *, void *);
} t_call;

	/* echo */
size_t print_seq(char*, FLAG, BOOL*);
int	my_echo(t_words *, void *);
# define ECHO_N	0b001
# define ECHO_E 0b010

int	setenv(t_words *, void *);
int	unsetenv(t_words *, void *);
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
