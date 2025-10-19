##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## 凸( •̀_•́ )凸
##

SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAME_LIB = libmy.a

NAME_HEADER = my.h

UNUSED_FLAG = -Wunused-command-line-argument

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	clang -c $(OBJ) $(UNUSED_FLAG)
	ar rc $(NAME_LIB) $(OBJ)
	cp $(NAME_LIB) ../../
	cp ../../include/$(NAME_HEADER) .
	make clean

clean : $(shell rm -f $(OBJ))
	rm -f $(NAME_HEADER)

fclean : rm -f ../../$(NAME_LIB)
