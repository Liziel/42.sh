#include	<stdlib.h>
#include	"lexec.h"

int		exec_form(t_words *list, char *av[])
{
  char		**tab;

  tab = xmalloc(sizeof(char *) * 2);
  tab[0] = list->word;
  tab[1] = NULL;
  if (execve(tab[0], av, environ) == -1)
    return (1);
  return (0);
}
