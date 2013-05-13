/*
** echo.c for  in /home/collio_v/rendu_svn/42.sh/42/src/builtins
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:49:09 2013 vincent colliot
** Last update Mon May 13 15:44:06 2013 thomas lecorre
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"

/*
**compte tu utilisé malloc dans les modif' prochaine de ton echo?
*/

int	echo_n(t_words *cmd)
{
  while (cmd != NULL)
    {
      if (cmd->word)
	{
	  my_putstr(cmd->word);
	  if (cmd->next != NULL)
	    my_putstr(" ");
	}
      cmd = cmd->next;
    }
}

int	echo_options(t_words *cmd)
{
      cmd = cmd->next;
      if (cmd->word[1] == 'n')
	echo_n(cmd);
      if (cmd->word[1] == 'e')
	echo_e(cmd);
      if (cmd->word[1] == 'E')
	echo_E(cmd);
}

int	echo(t_words *cmd, void *alias)
{
  if (cmd->next == NULL)
    {
      my_putstr('\n');
      return (EXIT_SUCCES);
    }
  else if (cmd->next->word[0] != '-')
    {
      while (cmd != NULL)
	{
	  if (cmd->word)
	    {
	      my_putstr(cmd->word);
	      if (cmd->next != NULL)
		my_putstr(" ");
	    }
	  cmd = cmd->next;
	}
      my_putchar('\n');
    }
  else
    echo_options(cmd);
  return (EXIT_SUCCES);
}
