/*
** my_echo.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue May 14 18:25:48 2013 thomas lecorre
** Last update Wed May 15 15:25:35 2013 thomas lecorre
*/

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
      if (*str == '\v')
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
      if (*str == '\f')
	{
	  my_putchar('\\');
	  my_putchar('f');
	}
      else
	my_putchar(*str);
      *str++;
    }
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
  return (EXIT_SUCCES);
}

int	echo_E(t_words *cmd)
{
  while (cmd != NULL)
    {
      if (cmd->word)
	my_print_echo(cmd->word);
      if (cmd->next != NULL)
	my_putstr(" ");
      cmd = cmd->next;
    }
  return (EXIT_SUCCES);
}

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
  if (flag_e && flag_n == 0)
    {
      echo_e(cmd);
      my_putchar('\n');
    }
  if (flag_E && flag_n == 0)
    {
      echo_E(cmd);
      my_putchar('\n');
    }
  if (flag_e && flag_n)
    echo_e(cmd);
  if (flag_E && flag_n)
    echo_E(cmd);
  return (EXIT_SUCCES);
}
