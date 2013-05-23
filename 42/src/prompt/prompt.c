/*
** prompt.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 20 22:23:52 2013 vincent colliot
** Last update Wed May 22 22:56:37 2013 vincent colliot
*/

#include <unistd.h>
#include "string.h"
#include "prompt.h"
#include "env.h"
#include "string.h"

static size_t inter_prompt(char *s, size_t h, size_t n)
{
  BOOL		end;
  size_t	next;

  if ((h && n >= h) || !s[0])
    return (0);
  end = FALSE;
  next = print_seq(s, 3, &end);
  if (end)
    return (0);
  return (1 + inter_prompt((s + next), h, n + next));
}

size_t	prompt(BOOL b)
{
  char		*p;

  p = get_env("PS1");
  if (!p)
    p = "------>Prompt test\n[Sla.sh] ";
  if (!b)
    {
      if (last_soccur(p, "\\n") < last_occur(p, '\n', 0))
	p += last_occur(p, '\n', 0) + IN('\n', p);
      else
	p += last_soccur(p, "\\n") + S_IN("\\n", p) * 2;
    }
  if (b && !IN('\n', p) && !S_IN("\\n", p))
    return (0);
  if (last_soccur(p, "\\n") < last_occur(p, '\n', 0))
    return (inter_prompt(p, last_occur(p, '\n', 0) + IN('\n', p), 0));
  else
    return (inter_prompt(p, last_soccur(p, "\\n") + S_IN("\\n", p) * 2, 0));
}
