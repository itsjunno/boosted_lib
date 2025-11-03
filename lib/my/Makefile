##
## EPITECH PROJECT, 2025
## Makefile
## File description:
##
##

SRC =	my_put_unsigned_nbr.c		\
	handle_unsigned_nbr.c		\
	handle_nbr.c			\
	handle_int_hex.c		\
	handle_f_or_e.c			\
	handle_nbr.c			\
	handle_percent.c		\
	flag_checker.c			\
	handle_char.c			\
	my_put_nbr.c			\
	handle_scientific.c		\
	my_putstr.c			\
	handle_string.c			\
	my_strlen.c			\
	my_strupcase.c			\
	my_printf.c			\
	specifiers_handlers.c		\
	my_printf_parser.c		\
	my_putchar.c			\
	handle_float.c			\

OBJ = $(SRC:.c=.o)

NAME_LIB = libmy.a

NAME_HEADER = my.h

UNUSED_FLAG = -Wunused-command-line-argument

RM_FLAG = rm -f

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	ranlib $(NAME_LIB)
	cp libmy.a ../../

clean:
	$(RM_FLAG) $(OBJ)
	$(RM_FLAG) $(NAME_HEADER)

fclean: clean
	$(RM_FLAG) $(NAME_LIB)

re: fclean all

.PHONY: all clean fclean re
