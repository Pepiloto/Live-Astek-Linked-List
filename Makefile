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
SRC			=	src/main.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_train

IDIR		=	./include

CC			=	gcc

######### Rules ###########
all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

debug:	CPPFLAGS += -g3
debug: re
debug:
	make debug -C lib/my/

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all

reset: all
	@$(RM) .config/maps/* .config/save
	@./$(NAME) --reset

.PHONY: all debug clean fclean re tests_run reset

tests_run:	LDFLAGS	+= -lcriterion --coverage
tests_run:
		gcc -o unit_tests  $(CPPFLAGS) $(LDFLAGS)
		./unit_tests
		gcovr -e tests/
