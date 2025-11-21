##
## EPITECH PROJECT, 2025
## my_hunter
## File description:
## Makefile for my_hunter project
##

SRC	=	src/main.c		\
		src/init.c		\
		src/game_loop.c	\
		src/duck.c		\
		src/gun.c		\
		src/cleanup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-Wall -Wextra -I.

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
