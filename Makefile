##
## Makefile for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Fri Apr  7 15:15:01 2017 Sahel Lucas--Saoudi
## Last update Tue May 16 14:08:56 2017 Thomas GRANDJEAN
##

SRC	=	src/main.c			\
		src/builtins/env.c		\
		src/builtins/setenv.c		\
		src/parseur/parse_.c		\
		src/free_tab.c			\
		src/epur.c			\
		src/set_var.c			\
		src/concat_free.c		\
		src/add_str.c			\
		src/command/manage.c		\
		src/path.c			\
		src/add_and_free.c		\
		src/add_char.c			\
		src/command/validity.c		\
		src/command/lexer.c		\
		src/without_before_.c		\
		src/only_before.c		\
		src/command/double_redir.c	\
		src/command/error.c		\
		src/builtins/cd.c		\
		src/builtins/setenv_isValid.c	\
		src/builtins/unsetenv.c		\
		src/dico.c			\
		src/command/pipe.c		\
		src/builtins/exit.c		\
		src/command/redir.c		\
		src/setup.c			\
		src/command/command_validity.c	\
		src/close.c			\
		src/command/end.c		\
		src/globing/globing.c		\
		src/command/file.c		\
		src/command/parser_and_or.c	\
		src/alias/alias.c		\
		src/builtins/echo.c		\
		src/get_input.c			\
		src/history/history.c		\
		src/put_minimalist.c		\
		src/builtins/where.c		\
		src/builtins/which.c		\
		src/builtins/check_where.c	\
		src/builtins/check_which.c	\
		src/builtins/repeat.c		\
		martin/src/main.c		\
		martin/src/found_term.c		\
		martin/src/check_is_key.c	\
		martin/src/reset_line.c		\
		martin/src/is_a_key.c		\
		martin/src/start_end.c		\
		martin/src/ini_keys.c		\
		martin/basics/my_free.c		\
		martin/basics/my_realloc.c	\
		martin/basics/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Iinclude

LIB	=	-Llib -lbasic

NAME	=	42sh

MLIB	=	basic

all:	$(NAME)

$(MLIB):
	make -C lib

$(NAME):	 $(MLIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) -lncurses

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(MLIB) all

debug: CFLAGS += -ggdb3

debug: fclean $(MLIB) all

.PHONY:	all clean fclean re debug
