/*
** echo.c for  in /home/collio_v/rendu_svn/42.sh/42/src/builtins
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:49:09 2013 vincent colliot
** Last update Sun May 12 01:04:49 2013 vincent colliot
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"

/*
**compte tu utilisé malloc dans les modif' prochaine de ton echo?
*/
int	echo(t_words *cmd, void *alias)
{
  if (cmd->next == NULL)
    {
      my_putstr('\n');
      return (EXIT_SUCCES);
    }
  else
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
  return (EXIT_SUCCES);
}
