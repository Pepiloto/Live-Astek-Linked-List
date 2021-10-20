##
## EPITECH PROJECT, 2020
## ${PROJECT}
## File description:
## Sources for ${MODULE} part
##

${MODULE}_FILES	=	destroy.c	\
					draw.c		\
					event.c		\
					init.c		\
					update.c	\

${MODULE}_SRC	=	$(addprefix ${FOLDER}, ${MODULE}_FILES)
