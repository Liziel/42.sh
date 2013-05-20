/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Mon May 20 22:18:12 2013 vincent colliot
*/

#include <unistd.h>
#include <stdlib.h>
#include "get.h"
#include "orga.h"
#include "edit_line.h"
#include "string.h"
#include "alias.h"
#include "env.h"

int main(void)
{
  t_info        info;

  info.alias = NULL;
  load_tgets_funcs();
  attribute_options(&(info.termcaps));
  retain_struct_options(1, &(info.termcaps));
  read_cmds(&info);
  return (info.st);
  /* char *test; */
  /* BOOL	null; */
  /* char  *bad_sintax; */
  /* t_info	info; */
  /* t_get *g; */
  /* t_jobs	*j; */
  /* t_alias	*a; */

  /* environ = env_copy(); */
  /* info.alias = NULL; */
  /* attribute_options(&(info.termcaps)); */
  /* bad_sintax = NULL; */
  /* my_putstr("Sla.sh -> ", 1); */
  /* while (test = get_next_line(0)) */
  /*   { */
  /*     if (bad_sintax) */
  /* 	free(bad_sintax); */
  /*     bad_sintax = NULL; */
  /*     if ((g = subdivide(test, NULL, &bad_sintax)) == NULL) */
  /* 	{ */
  /* 	  if (bad_sintax) */
  /* 	    { */
  /* 	      print_err(bad_sintax); */
  /* 	      print_err("\n"); */
  /* 	    } */
  /* 	} */
  /*     else */
  /* 	{ */
  /* 	  if ((g = comment(g, NULL)) == NULL) */
  /* 	    return (-1); */
  /* 	  if ((j = orga(g, &bad_sintax, &null)) == NULL) */
  /* 	    { */
  /* 	      if (bad_sintax) */
  /* 		{ */
  /* 		  print_err(bad_sintax); */
  /* 		  print_err("\n"); */
  /* 		} */
  /* 	    } */
  /* 	  else */
  /* 	    { */
  /* 	      info.st = EXIT_SUCCESS; */
  /* 	      if (pre_exec(j, &info) == FALSE) */
  /* 		return (info.st); */
  /* 	    } */
  /* 	} */
  /*     free(test); */
  /*     my_putstr("Sla.sh -> ", 1); */
  /*   } */
  /* return (0); */
}
