##
## Makefile for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Fri Apr  7 15:15:01 2017 Sahel Lucas--Saoudi
## Last update Wed May 17 13:36:15 2017 Thomas GRANDJEAN
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
		src/line_editing/line.c		\
		src/line_editing/found_term.c	\
		src/line_editing/check_is_key.c	\
		src/line_editing/reset_line.c	\
		src/line_editing/is_a_key.c	\
		src/line_editing/start_end.c	\
		src/line_editing/ini_keys.c	\
		src/line_editing/my_realloc.c

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
