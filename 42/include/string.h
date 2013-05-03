/*
** string.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Apr 29 20:25:19 2013 vincent colliot
** Last update Fri May  3 17:35:27 2013 vincent colliot
*/

#ifndef STRING_H_
# define STRING_H_

# include <stdlib.h>
# include <string.h>
# include "bool.h"

# define IN(c, s) (s[my_strilen(s, c)] != 0)
# define S_IN(c, s) (s[my_strslen(s, c)] != 0)
# define LS_IN(c, s, n) (s[my_strnslen(s, c, n)] != 0)
# define MATCH(s, c) ((s && c) ? (!my_strcmp(s, c)) : (0))
# define NMATCH(s, c) (((s) && (c)) ? \
		       (!my_strncmp((s), (c), my_strlen(s))) : (0))
# define FNMATCH(s, c, n) (((s) && (c)) ?					\
		       (!my_strncmp((s), (c), n)) : (0))

	/* s_lenth */
size_t my_strlen(const char*);
size_t my_strilen(const char*, char);
size_t my_strslen(const char*, const char*);
size_t my_sstrlen(const char*, const char*);
size_t lenmatch(const char *s, const char *c);

	/* s_alloc */
char	*my_strdup(const char*);
void	*my_strndup(const void*, size_t);

	/* s_match */
BOOL	empty(const char *s);
BOOL	nempty(const char *s, size_t n);
size_t	hempty(const char *s);

	/* s_alloc */
int	my_strcmp(const char *s1, const char *s2);
int	my_strncmp(const char *s1, const char *s2, size_t n);

	/* match */
size_t	my_strnslen(const char *s, const char *c, size_t n);
BOOL	match(const char *s, const char *c);

	/* s_print */
size_t	print_err(const char *s);

#endif
