/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Tue May 21 21:30:36 2013 vincent colliot
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
  info.st = 0;
  environ = env_copy();
  if (load_tgets_funcs() == -1)
    return (EXIT_FAILURE);
  attribute_options(&(info.termcaps));
  retain_struct_options(1, &(info.termcaps));
  read_cmds(&info);
  destroy_env();
  return (info.st);
}
