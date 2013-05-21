/*
** my_echo.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue May 14 18:25:48 2013 thomas lecorre
** Last update Tue May 21 18:18:14 2013 vincent colliot
*/

#include "built.h"
#include "flag.h"
#include "string.h"

static BOOL print(FLAG echo, t_words *link)
{
  BOOL		end;
  size_t	i;

  if (!link)
    return (TRUE);
  end = FALSE;
  i = 0;
  while ((link->word)[i] && !end)
    {
      i += print_seq(link->word + i, echo, &end);
      if (end)
	return (FALSE);
    }
  if (link->next)
    my_putchar(' ', 1);
  return (print(echo, link->next));
}

static void move_flag(t_words *link, t_words **move, FLAG *echo)
{
  *move = link;
  if (!link)
    return ;
  if (MATCH("-e", link->word))
    *echo |= ECHO_E;
  else if (MATCH("-E", link->word))
    *echo &= ~ECHO_E;
  else if (MATCH("-n", link->word))
    *echo |= ECHO_N;
  else
    return ;
  move_flag(link->next, move, echo);
}

int	built_echo(t_words *cmd, void *null)
{
  FLAG  echo;

  echo = 0;
  (void)null;
  move_flag(cmd->next, &cmd, &echo);
  if (print(echo, cmd) == FALSE)
    return (EXIT_SUCCESS);
  if (!(echo & ECHO_N))
    my_putstr("\n", 1);
  return (EXIT_SUCCESS);
}
