#include	<stdlib.h>
#include	"lexec.h"

static int	list_len(t_words *list)
{
  int		i;

  i = 0;
  while (tmp->next !⁼ NULL)
    {
      tmp = tmp->next;
      i++;
    }
}

char		**create_exec_stuff(t_words *list, char **tab)
{
  t_words	*tmp;
  int		i;

  i = 0;
  while (list->next != NULL)
    {
      tab[i++] = list->word;
      list = list->next;
    }
  return (tab);
}

int		exec_form(t_words *list, char *av[])
{
  char		**tab;

  tmp = list;
  tab = xmalloc(sizeof(char *) * (list_len(tmp) + 1));
  tab[i + 1] = NULL;
  tab = create_exec_stuff(list, tab);
  i = 0;
  while (execve(tab[i], av, environ) == -1)
    {
      if (tab[i] == NULL)
	return (1);
      i += 1;
    }
  return (0);
}
