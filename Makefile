##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## 凸( •̀_•́ )凸
##

NAME = info_file

CC = epiclang

RM = rm -f

SRC = my_bs.c

OBJ = $(SRC:.c=.o)

LIBFLAG = -L./lib/my/ -lmy

INCLUDEFLAG = -I./include

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) -o $(NAME) $(LIBFLAG)

%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDEFLAG)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) libmy.a

re: fclean all

.PHONY: all clean fclean re

tests_run:
	gcc -o tests_cat ../tests/tests_cat.c -lcriterion --coverage
	./tests_cat
	rm -f tests_cat
