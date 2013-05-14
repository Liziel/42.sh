/*
** cd.c for cd in /home/cloare_q//42.sh/42/src/builtins
**
** Made by quentin cloarec
** Login   <cloare_q@epitech.net>
**
** Started on  Mon May 13 11:58:06 2013 quentin cloarec
** Last update Mon May 13 15:56:42 2013 thomas lecorre
*/

#include <unistd.h>
#include "stdlib.h"
#include "env.h"
#include "built.h"
#include "string.h"

char	*put_pwd(char *s)
{
  char *pwd;
  int	i;
  int	j;

  j = 0;
  if ((pwd = xmalloc(sizeof(char) * (my_strlen(s) + 5))) == NULL)
    return (EXIT_FAILURE);
  pwd[0] = 'T';
  pwd[1] = 'M';
  pwd[2] = 'P';
  pwd[3] = ' ';
  i = 4;
  while (s[j])
    pwd[i++] = s[j++];
  return (pwd);
}

int	just_cd(t_words *cmd)
{
  if ((chdir(get_env("HOME"))) == -1)
    {
      print_err("CHDIR ERROR\n");
      return (EXIT_FAILURE);
    }
}

int	cd(t_words *cmd, void *alias)
{
  int	i;
  char	*str;

  cmd = cmd->next;
  if (MATCH(cmd->word, "cd") == 1)
    {
      just_cd(cmd);
      str = put_pwd(get_env("HOME"));
      add_env(str);
    }
  else if (MATCH(cmd->word, "cd -") == 1)
    {
      if ((chdir(get_env("TMP"))) == -1)
	{
	  print_err("CHDIR ERROR\n");
	  return (EXIT_FAILURE);
	}
      str = put_pwd(get_env("PWD"));
      add_env(str);
    }
  else
    {
      if ((chdir(cmd->word)) == -1)
	{
          print_err("CHDIR ERROR\n");
          return (EXIT_FAILURE);
        }
      str = put_pwd(cmd->word);
      add_env(str);
    }
}
