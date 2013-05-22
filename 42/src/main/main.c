/*
** main.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Apr 27 09:09:51 2013 vincent colliot
** Last update Wed May 22 16:06:13 2013 quentin cloarec
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
  BOOL		tget_fail;
  t_info        info;

  info.alias = NULL;
  info.st = 0;
  environ = env_copy();
  set_env("PS1", "[you are in Sla.sh] (you can set your prompt with setenv PS1 \"your_prompt\")\n[ --> ] ");
  if (load_tgets_funcs() == -1)
    tget_fail = TRUE;
  attribute_options(&(info.termcaps));
  retain_struct_options(1, &(info.termcaps));
  read_cmds(&info, tget_fail);
  destroy_env();
  return (info.st);
}
