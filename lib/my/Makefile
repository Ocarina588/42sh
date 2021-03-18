##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile lib
##

SRC	=	convertbis.c	\
		free.c	\
		convert.c	\
		fprintf.c	\
		my_char_isalphanum.c	\
		my_getnbr.c	\
		my_istrncat.c	\
		nb_len.c	\
		my_printf.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strncpy.c	\
		my_str_to_word_array.c	\
		print_pourcent.c	\
		void_functionbis.c	\
		void_function.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

valgrind:
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAME) $(SRC) -W -Wall -extra -g
