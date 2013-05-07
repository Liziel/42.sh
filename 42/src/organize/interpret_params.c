/*
** interpret_params.c for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May  6 20:09:42 2013 vincent colliot
** Last update Mon May  6 20:17:14 2013 vincent colliot
*/

t_words		*interpret_params(t_get *word, t_get **words, char **bad_sintax,
				  t_get **last)
{
  BOOL		no_match;
  t_words	*params;

  no_match = FALSE;
  if (NMATCH("`", word->word))
    if ((params = back_quote(word, words, bad_sintax)) == NULL)
      return (NULL);
  if (!(!IN('*', word->word) || IN(word->word[0], "'\"")))
    if ((params = match(word, bad_sintax, &no_match))
}
