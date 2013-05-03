/*
** lexec.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May  2 19:45:44 2013 vincent colliot
** Last update Thu May  2 22:26:10 2013 vincent colliot
*/

#ifndef LEXEC_H_
# define LEXEC_H_

#include "flag.h"
#include "get.h"

struct s_exec;

# define REF 0b01
# define WORD 0b10
typedef struct s_words{
  FLAG type;
  char *word;
  struct s_exec *ref;
  struct s_words *next;
}		t_words;

# define ON_CANAL 0b01
# define ON_FILE 0b10
typedef struct s_redir{
  FLAG type;
  FD in;
  FD out;
  char *file;
}		t_redir;

	/* type */
# define PARENTS 0b01
# define WORDS	0b10
typedef struct s_cmd{
  FLAG	job;
  struct s_redir *redir;
  FLAG	type;
  struct s_word *params;
  /* or */
  struct s_exec *parents;
}		t_cmd;

typedef struct s_pipes{
  struct s_pipes *next;
  struct s_get	*tmp;
  struct s_cmd	*cmd;
}		t_pipes;

# define OR 0b001
# define AND 0b010
# define NEXT 0b100
typedef struct s_exec{
  FLAG	type;
  struct s_exec *next;
  struct s_pipe *pipes;
  struct s_get  *tmp;
}		t_exec;

# define NONE 0b0
# define JOBS 0b1
typedef struct s_jobs{
  FLAG type;
  struct s_jobs *next;
  struct s_exec *exec;
  struct s_get  *tmp;
}		t_jobs;

#endif
