/*
** exec_form.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun May 12 01:40:28 2013 vincent colliot
** Last update Sat May 18 13:36:58 2013 vincent colliot
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "lexec.h"
#include "xmalloc.h"
#include "status.h"
#include "string.h"
#include "env.h"
#include "father.h"

static size_t	size_list(t_words *list)
{
  size_t	i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return (i);
}

static char	**to_tab(t_words *list, BOOL *sys_fail)
{
  char		**tab;
  size_t	i;

  i = size_list(list);
  if ((tab = xmalloc(sizeof(*tab) * (i + 1))) == NULL)
    {
      (*sys_fail) = TRUE;
      return (NULL);
    }
  i = 0;
  while (list)
    {
      tab[i] = list->word;
      list = list->next;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

static void	clean_signal(STATUS signal)
{
  if (signal == SIGILL)
    my_putstr("Illegal instruction\n", 2);
  else if (signal == SIGABRT)
    my_putstr("Aborted\n", 2);
  else if (signal == SIGFPE)
    my_putstr("Floating exeception\n", 2);
  else if (signal == SIGSEGV)
    my_putstr("Segmentation fault\n", 2);
  else if (signal == SIGTERM)
    my_putstr("Terminated\n", 2);
  else if (signal == SIGINT)
    my_putstr("\n", 2);
}

STATUS		exec_form(t_words *list, BOOL *sys_fail, BOOL son)
{
  STATUS	st;
  pid_t		pid;
  char		**tab;

  if ((tab = to_tab(list, sys_fail)) == NULL)
    return (EXIT_FAILURE + !((*sys_fail) = TRUE));
  if ((pid = fork()) == -1)
    return (EXIT_FAILURE + !((*sys_fail) = TRUE));
  if (pid)
    waitpid(pid, &st, 0);
  else
    if (execve(tab[0], tab, environ) == -1)
      return (EXIT_FAILURE + !((*sys_fail) = TRUE));
  clean_signal(st);
  free(tab);
  return (0 != (WEXITSTATUS(st)));
}
