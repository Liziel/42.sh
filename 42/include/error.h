/*
** error.h for  in /home/collio_v/rendu_svn/42.sh/42
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May  4 12:44:30 2013 vincent colliot
** Last update Sat May 18 03:53:21 2013 vincent colliot
*/

#ifndef ERROR_H_
# define ERROR_H_

# define UNMATCHED_TOKEN "(sh): unexpected EOS while looking for matching `"
# define ERROR_AFTER_ECHAP_CHAR "(sh): unextpected EOS after echappment character"
# define UNMATCHED_PARENTS "(sh): syntax error near unexpected token `)'"
# define UNMATCHED_BACKMACHIN "(sh): syntax error near unexpected token ``'"
# define UNKNOW_CMD "(sh): command not found : "
# define WRONG_SEP_TOKEN "(sh): sintax error neat unexpected token `"
# define WRONG_REDIR "(sh): wrong redirection"
# define ERROR_IN_REDIR "(sh): unexpected EOS after redirection"
# define FILE_ERROR "(sh): no such file: "
# define DIR_ERROR "(sh): no such direcotry: "
# define IS_DIR_ERROR1 "(sh):error : "
# define IS_DIR_ERROR2 " : is a directory"
# define INVALID_ALIAS "(sh): alias error: invalid character in sentence: "

#endif
