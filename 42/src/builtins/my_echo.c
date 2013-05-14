/*
** my_echo.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue May 14 18:25:48 2013 thomas lecorre
** Last update Tue May 14 18:54:07 2013 thomas lecorre
*/

#include "built.h"

void	find_opt(t_words *cmd, int *n, int *e, int *E)
{
  int	i;

  while (cmd != NULL)
    {
      i = 0;
      if (cmd->word && cmd->word[i] == '-')
	while (cmd->word[i])
	  {
	    if (cmd->word[i] == 'n')
	      *n = 1;
	    if (cmd->word[i] == 'e')
	      {
		*e = 1;
		*E = 0;

	      }
	    if (cmd->word[i] == 'E')
	      {
		*E = 1;
		*e = 0;
	      }
	    i++;
	  }
      cmd = cmd->next;
    }
}

int	my_echo(t_words *cmd, void *alias)
{
  int	flag_n;
  int	flag_e;
  int	flag_E;

  flag_n = 0;
  flag_e = 0;
  flag_E = 0;
  if (cmd->next == NULL)
    {
      my_putstr('\n');
      return (EXIT_SUCCES);
    }
  cmd = cmd->next;
  find_opt(cmd, &flag_n, &flag_e, &flag_E);
  return (EXIT_SUCCES);
}
