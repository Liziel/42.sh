## Makefile for make_my in /u/all/collio_v/rendu/piscine/Jour_13/cat
##
## Made by vincent colliot
## Login   <collio_v@epitech.net>
##
## Started on Thu Oct 25 22:06:03 2012 vincent colliot
## Last update Thu May  9 01:01:01 2013 vincent colliot
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

###### Parsing #########

ORGAF	=$(SRCF)organize/

CMDF	=$(ORGAF)cmd/
CMD	=$(CMDF)cmd.c\
	$(CMDF)cmd_part.c\
	$(CMDF)interpret_cmd.c\
	$(CMDF)interpret_params.c

JEXEF	=$(ORGAF)jobs_exec/
JEXE	=$(JEXEF)exec.c\
	$(JEXEF)jobs.c\
	$(JEXEF)match_them.c

ORJF	=$(ORGAF)orga/
ORJ	=$(ORJF)nullify.c\
	$(ORJF)orga.c\
	$(ORJF)parenthesys.c\

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
	$(DIR)\

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
