/*
** my_echo.c for  in /home/lecorr_b//projets/42sh/42.sh/42/src/builtins
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue May 14 18:25:48 2013 thomas lecorre
** Last update Sun May 19 04:46:24 2013 vincent colliot
*/

#include "built.h"
#include "flag.h"
#include "string.h"

static void print(FLAG echo, t_words *link)
{
  BOOL		end;
  size_t	i;

  if (!link)
    return ;
  end = FALSE;
  i = 0;
  while ((link->word)[i] && !end)
    i += print_seq(link->word + i, echo, &end);
  if (end)
    return ;
  if (link->next)
    my_putchar(' ', 1);
  print(echo, link->next);
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
  move_flag(cmd, &cmd, &echo);
  print(echo, cmd);
  if (echo & ECHO_N)
    my_putstr("\n", 1);
  return (EXIT_SUCCESS);
}

/* -- -- -- -- -- -- -- -- -- */

/* void	my_print_echo(char *str) */
/* { */
/*   while (*str) */
/*     { */
/*       if (MATCH(str, "\\n")) */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('n'); */
/* 	} */
/*       if (*str == '\t') */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('t'); */
/* 	} */
/*       if (*str == '\v') */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('v'); */
/* 	} */
/*       if (*str == '\t') */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('t'); */
/* 	} */
/*       if (*str == '\b') */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('b'); */
/* 	} */
/*       if (*str == '\a') */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('a'); */
/* 	} */
/*       if (*str == '\f') */
/* 	{ */
/* 	  my_putchar('\\'); */
/* 	  my_putchar('f'); */
/* 	} */
/*       else */
/* 	my_putchar(*str); */
/*       *str++; */
/*     } */
/* } */

/* int	echo_e(t_words *cmd) */
/* { */
/*   while (cmd != NULL) */
/*     { */
/*       if (cmd->word) */
/* 	{ */
/* 	  while (*cmd->word) */
/* 	    { */
/* 	      if (*cmd->word == '\\' && *cmd->word + 1 == 'c') */
/* 		return (EXIT_SUCCES); */
/* 	      my_putchar(*cmd->word); */
/* 	    } */
/* 	  if (cmd->next != NULL) */
/* 	    my_putstr(" "); */
/* 	} */
/*       cmd = cmd->next; */
/*     } */
/*   return (EXIT_SUCCES); */
/* } */

/* int	echo_E(t_words *cmd) echo -> -e -> "ls \\n" */
/* { */
/*   while (cmd != NULL) */
/*     { */
/*       if (cmd->word) */
/* 	my_print_echo(cmd->word); */
/*       if (cmd->next != NULL) */
/* 	my_putstr(" "); */
/*       cmd = cmd->next; */
/*     } */
/*   return (EXIT_SUCCES); */
/* } */

/* void	find_opt(t_words *cmd, int *n, int *e, int *E) */
/* { */
/*   int	i; */

/*   while (cmd != NULL) */
/*     { */
/*       i = 0; */
/*       if (cmd->word && cmd->word[i] == '-') */
/* 	while (cmd->word[i]) */
/* 	  { */
/* 	    if (cmd->word[i] == 'n') */
/* 	      *n = 1; */
/* 	    if (cmd->word[i] == 'e') */
/* 	      { */
/* 		*e = 1; */
/* 		*E = 0; */

/* 	      } */
/* 	    if (cmd->word[i] == 'E') */
/* 	      { */
/* 		*E = 1; */
/* 		*e = 0; */
/* 	      } */
/* 	    i++; */
/* 	  } */
/*       cmd = cmd->next; */
/*     } */
/* } */

/* int	my_echo(t_words *cmd, void *alias) */
/* { */
/*   int	flag_n; */
/*   int	flag_e; */
/*   int	flag_E; */

/*   flag_n = 0; */
/*   flag_e = 0; */
/*   flag_E = 0; */
/*   if (cmd->next == NULL) */
/*     { */
/*       my_putstr('\n'); */
/*       return (EXIT_SUCCES); */
/*     } */
/*   cmd = cmd->next; */
/*   find_opt(cmd, &flag_n, &flag_e, &flag_E); */
/*   if (flag_e && flag_n == 0) */
/*     { */
/*       echo_e(cmd); */
/*       my_putchar('\n'); */
/*     } */
/*   if (flag_E && flag_n == 0) */
/*     { */
/*       echo_E(cmd); */
/*       my_putchar('\n'); */
/*     } */
/*   if (flag_e && flag_n) */
/*     echo_e(cmd); */
/*   if (flag_E && flag_n) */
/*     echo_E(cmd); */
/*   return (EXIT_SUCCES); */
/* } */
