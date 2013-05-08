/*
** interpret_params.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:09:42 2013 vincent colliot
** Last update Wed May  8 17:02:52 2013 vincent colliot
*/

t_words		*interpret_params(t_get *word, t_get **words, char **bad_sintax,
				  t_get **last)
{
  BOOL		no_match;
  t_words	*params;

  params = NULL;
  no_match = TRUE;
  if (NMATCH("`", word->word))
    if ((params = back_quote(word, words, bad_sintax)) == NULL)
      return (NULL);
  if (match_sentence(word->word, bad_sintax, last, &no_match) == FALSE)
    if (no_match)
      return (NULL);
  *words = word->next;
  if (no_match == TRUE)
    {
      if ((params = xmalloc(sizeof(*link))) == NULL)
	return (NULL);
      params->word = word->word;
      paras->next = NULL;
      (*last)->next = params;
      *last = params;
    }
  free(word);
  return (*last);
}
