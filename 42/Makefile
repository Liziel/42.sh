## Makefile for make_my in /u/all/collio_v/rendu/piscine/Jour_13/cat
##
## Made by vincent colliot
## Login   <collio_v@epitech.net>
##
## Started on Thu Oct 25 22:06:03 2012 vincent colliot
## Last update Mon May 13 13:44:32 2013 pierre-yves thomas
##

NAME    = 42.sh

RM      = rm -f

FO	=./

SRCF	=$(FO)src/

########################

MAINF	=$(SRCF)main/
MAIN	=$(MAINF)main.c\

LIBF	=$(SRCF)lib/
LIB	=$(LIBF)s_alloc.c\
	$(LIBF)s_match.c\
	$(LIBF)s_comp.c\
	$(LIBF)s_lenth.c\
	$(LIBF)s_print.c\
	$(LIBF)match.c\

XMALLOC=$(LIBF)xmalloc.c\

PARSF	=$(SRCF)parsing/
PARS	=$(PARSF)subdiv.c\

ENVF	=$(SRCF)env/
ENV	=$(ENVF)get_env.c\

DIRF	=$(SRCF)directory/
DIR	=$(DIRF)directory_in.c

EDITF	=$(SRCF)edit_line/
EDIT	=$(EDITF)edit_line.c\
	$(EDITF)load_term_settings.c\
	$(EDITF)modify_line.c\
	$(EDITF)show_cmd.c\

###### Parsing #########

ORGAF	=$(SRCF)organize/

CMDF	=$(ORGAF)cmd/
CMD	=$(CMDF)cmd.c\
	$(CMDF)cmd_part.c\
	$(CMDF)interpret_cmd.c\
	$(CMDF)interpret_params.c\
	$(CMDF)redir.c

JEXEF	=$(ORGAF)jobs_exec/
JEXE	=$(JEXEF)exec.c\
	$(JEXEF)jobs.c\
	$(JEXEF)match_them.c

ORJF	=$(ORGAF)orga/
ORJ	=$(ORJF)orga.c\
	$(ORJF)parenthesys.c\

NULLF	=$(ORGAF)nullify/
NULL	=$(NULLF)null1.c\
	$(NULLF)null2.c\

PIPEF	=$(ORGAF)pipe/
PIPE	=$(PIPEF)pipes.c\

ORGA	=$(CMD)\
	$(JEXE)\
	$(ORJ)\
	$(PIPE)\

########################

SRC     =$(MAIN)\
	$(LIB)\
	$(PARS)\
	$(XMALLOC)\
	$(ORGA)\
	$(ENV)\
	$(EDIT)\
	$(DIR)\
	$(NULL)\

########################

INC	=-I $(FO)include/

CFLAGS	= -Wall -Wextra $(INC)

DOTO    = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(DOTO)
	cc -o $(NAME) $(DOTO) $(CFLAGS)

debug: fclean
	cc -o $(NAME) $(SRC) $(INC) -g3

clean:
	$(RM) $(DOTO)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean
