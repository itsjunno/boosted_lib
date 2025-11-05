##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_ls
##

NAME = my_ls

CC = epiclang

CFLAGS = -Wall -Wextra

RM = rm -f

SRC_DIR = ./src

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:.c=.o)

LIB_DIR = ./lib/my

LIBFLAG = -L$(LIB_DIR) -lmy

INCLUDEFLAG = -I./include

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(OBJ) -o $(NAME) $(LIBFLAG)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDEFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
