/*
** echo.c for  in /home/collio_v/rendu_svn/42.sh/42/src/builtins
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:49:09 2013 vincent colliot
** Last update Tue May 14 17:53:03 2013 thomas lecorre
*/

#include <stdlib.h>
#include "string.h"
#include "env.h"
#include "built.h"

void	my_print_echo(char *str)
{
  while (*str)
    {
      if (*str == '\n')
	{
	  my_putchar('\\');
	  my_putchar('n');
	}
      if (*str == '\t')
	{
	  my_putchar('\\');
	  my_putchar('t');
	}
      if (*str == '\v' || *str == '\f')
	{
	  my_putchar('\\');
	  my_putchar('v');
	}
      if (*str == '\t')
	{
	  my_putchar('\\');
	  my_putchar('t');
	}
      if (*str == '\b')
	{
	  my_putchar('\\');
	  my_putchar('b');
	}
      if (*str == '\a')
	{
	  my_putchar('\\');
	  my_putchar('a');
	}
      else
	my_putchar(*str);
      *str++;
    }
}

int	echo_n(t_words *cmd)
{
  while (cmd != NULL)
    {
      if (cmd->word)
	{
	  my_print_echo(cmd->word);
	  if (cmd->next != NULL)
	    my_putstr(" ");
	}
      cmd = cmd->next;
    }
  return (EXIT_SUCCES);
}

int	echo_E(t_words *cmd)
{
  while (cmd != NULL)
    {
      if (cmd->word)
	{
	  my_print_echo(cmd->word);
	  if (cmd->next != NULL)
	    my_putstr(" ");
	}
      cmd = cmd->next;
    }
  my_putchar('\n');
  return (EXIT_SUCCES);
}

int	echo_e(t_words *cmd)
{
  while (cmd != NULL)
    {
      if (cmd->word)
	{
	  while (*cmd->word)
	    {
	      if (*cmd->word == '\\' && *cmd->word + 1 == 'c')
		return (EXIT_SUCCES);
	      my_putchar(*cmd->word);
	    }
	  if (cmd->next != NULL)
	    my_putstr(" ");
	}
      cmd = cmd->next;
    }
  my_putchar('\n');
  return (EXIT_SUCCES);
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

int	my_echo(t_words *cmd, void *alias)
{
  if (cmd->next == NULL)
    {
      my_putstr('\n');
      return (EXIT_SUCCES);
    }
  else if (cmd->next->word && (((MATCH(cmd->next->word, "-n")) != 1) ||
			       ((MATCH(cmd->next->word, "-e")) != 1) ||
			       ((MATCH(cmd->next->word, "-E")) != 1)))
    echo_E(cmd->next);
  else
    echo_options(cmd);
  return (EXIT_SUCCES);
}
