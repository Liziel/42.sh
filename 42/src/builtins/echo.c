/*
** echo.c for  in /home/collio_v/rendu_svn/42.sh/42/src/builtins
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:49:09 2013 vincent colliot
** Last update Mon May  6 20:53:59 2013 vincent colliot
*/

static void interpret()

int	echo_print(char *s, FLAG flag)
{
  size_t	i;

  if (s[0])
    return ;
 i = 1;
  if (s[0] == '\\')
    intepret(/*truc qui print*/, flag, &i);
  else
    my_putchar(s[0]);
  echo_print(s + i, flag);
}

/*
**ici t'as un truc qui v a init tes flags il va aussi t'envoyer chaque chaine
*/
