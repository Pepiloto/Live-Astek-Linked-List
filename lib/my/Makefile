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
SRC			=	linked_list.c

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

IDIR		=	.

CC			=	gcc

######### Rules ###########
all:	$(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(LIB) $(OBJ)
	mv libmy.a ../

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all debug
