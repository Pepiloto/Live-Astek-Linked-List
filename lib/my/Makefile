##
## EPITECH PROJECT, 2021
## Live-Astek-Linked-List
## File description:
## Makefile
##

######### FLAGS #########
CFLAGS		=	-Wall -Wextra -Wshadow -finline-functions

CPPFLAGS	= -iquote $(IDIR)

DBGFLAGS	= -g3 -ggdb

LDFLAGS 	= -L lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

######### SOURCES #########
SRC			=	

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

IDIR		=	.

CC			=	gcc

######### Rules ###########
all:	$(NAME)

$(NAME):    $(OBJ)
	ar rc $(LIB) $(OBJ)
	mv $(LIB) ../
	cp my.h ../../include/

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(LIB)

re: fclean all

.PHONY: fclean clean re all debug
