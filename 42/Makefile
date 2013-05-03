## Makefile for make_my in /u/all/collio_v/rendu/piscine/Jour_13/cat
##
## Made by vincent colliot
## Login   <collio_v@epitech.net>
##
## Started on Thu Oct 25 22:06:03 2012 vincent colliot
## Last update Fri May  3 17:12:31 2013 vincent colliot
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

########################

SRC     =$(MAIN)\
	$(LIB)\
	$(PARS)\
	$(XMALLOC)\
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
