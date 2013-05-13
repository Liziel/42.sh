/*
** cd.c for cd in /home/cloare_q//42.sh/42/src/builtins
** 
** Made by quentin cloarec
** Login   <cloare_q@epitech.net>
** 
** Started on  Mon May 13 11:58:06 2013 quentin cloarec
** Last update Mon May 13 14:52:02 2013 quentin cloarec
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
  pwd[0] = 'P';
  pwd[1] = 'W';
  pwd[2] = 'D';
  i = 3;
  while (s[j])
    pwd[i++] = s[j++];
  return (pwd);
}

int	just_cd(t_words *cmd)
{
  if ((chdir(get_env("HOME"))) == -1)
    {
      my_putstr("CHDIR ERROR\n");
      return (EXIT_FAILURE);
    }
}

int	cd(t_words *cmd, void *alias)
{
  static char *pwd;
  static int	i;  
  char	*str;

  if (i == 0)
    {
      if ((pwd = xmalloc(sizeof(char) * (my_strlen(get_env("PWD")) + 1))) == NULL)
	return (EXIT_FAILURE);
      pwd = get_env("PWD");
    }
  cmd = cmd->next;
  if (MATCH(cmd->word, "cd") == 1)
    {
      just_cd(cmd);
      str = put_pwd(get_env("HOME"));
      put_env(str);
      if ((pwd = xmalloc(sizeof(char) * (my_strlen(get_env("PWD")) + 1))) == NULL)
	return (EXIT_FAILURE);
      pwd = get_env("PWD");
      i++;
    }
  else if (MATCH(cmd->word, "cd -") == 1)
    {
      if ((chdir(get_env("PWD"))) == -1)
	{
	  my_putstr("CHDIR ERROR\n");
	  return (EXIT_FAILURE);
	}
      if ((pwd = xmalloc(sizeof(char) * (my_strlen(get_env("PWD")) + 1))) == NULL)
        return (EXIT_FAILURE);
      pwd = get_env("PWD");
      i++;
    }
  else
    {
      if ((chdir(cmd->word)) == -1)
	{
          my_putstr("CHDIR ERROR\n");
          return (EXIT_FAILURE);
        }
      if ((pwd = xmalloc(sizeof(char) * (my_strlen(get_env("PWD")) + 1))) == NULL)
        return (EXIT_FAILURE);
      pwd = get_env("PWD");
    }
}
