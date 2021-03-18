##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile solostumper
##

SRC	=	src/main.c							\
		src/utils.c							\
		src/utils_bis.c						\
		src/built_in.c						\
		src/built_in_utils.c				\
		src/func_path.c						\
		src/len_path.c						\
		src/redirections/path_red.c			\
		src/redirections/double_red.c		\
		src/redirections/redirections.c		\
		src/redirections/stock_red.c		\
		src/built_in/history.c				\
		src/built_in/cd.c					\
		src/built_in/cd_err.c				\
		src/built_in/setenv_bis.c			\
		src/built_in/setenv.c				\
		src/built_in/setenv_utils.c			\
		src/built_in/unsetenv.c				\
		src/built_in/exit.c					\
		src/built_in/alias.c				\
		src/built_in/alias_bis.c			\
		src/built_in/unalias.c				\
		src/built_in/change_cmd_alias.c     \
		src/built_in/change_line_alias.c	\
		src/built_in/where.c				\
		src/built_in/echo_var.c				\
		src/built_in/echo_var_bis.c			\
		src/built_in/where2.c				\
		src/built_in/which.c				\
		src/built_in/repeat.c				\
		src/built_in/set.c					\
		src/built_in/set_bis.c				\
		src/free/free_all.c					\
		src/init_struct/init.c				\
		src/pipe/pipe.c						\
		src/pipe/manage_pipe.c				\
		src/pipe/make_pipe.c				\
		src/pipe/search_pipe.c				\
		src/pipe/close_and_dup.c			\
		src/pipe/parse_pipe.c				\
		src/pipe/retab_end.c				\
		src/parsing/get_variable.c			\
		src/parsing/put_argv.c				\
		src/parsing/parsing.c				\
		src/parsing/parsing_bis.c			\
		src/parsing/parsing_list.c			\
		src/parsing/parsing_function.c		\
		src/parsing/function_manager.c		\
		src/parsing/function_bis.c			\
		src/parsing/set_sep.c				\
		src/parsing/clean_utils.c			\
		src/parsing/parsing_function_bis.c	\
		src/parsing/interpreter_var.c		\
		src/parsing_errors/error_sep.c		\
		src/parsing_errors/parsing.c		\
		src/terminal/get_line.c				\
		src/terminal/line.c					\
		src/terminal/read.c					\
		src/terminal/terminal_function.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	42sh

CFLAGS	=	-I include/

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)


fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all

valgrind:
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) -W -Wall -extra -g -L./lib/my -lmy
	valgrind --leak-check=full ./$(NAME)