##
## Makefile for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
## 
## Made by Sahel Lucas--Saoudi
## Login   <sahel.lucas-saoudi@epitech.eu>
## 
## Started on  Fri Apr  7 15:15:01 2017 Sahel Lucas--Saoudi
## Last update Mon Apr 24 15:08:13 2017 Sahel Lucas--Saoudi
##

SRC	=	src/main.c			\
		src/env.c			\
		src/setenv.c			\
		src/parseur/parse_.c		\
		src/free_tab.c			\
		src/epur.c			\
		src/set_var.c			\
		src/get_next_line.c		\
		src/get_next_line2.c		\
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
		src/cd.c			\
		src/setenv_isValid.c		\
		src/unsetenv.c			\
		src/dico.c			\
		src/command/pipe.c		\
		src/exit.c			\
		src/command/redir.c		\
		src/setup.c			\
		src/command/command_validity.c	\
		src/close.c			\
		src/command/end.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Iinclude

LIB	=	-Llib -lbasic

NAME	=	mysh

MLIB	=	basic

all:	$(NAME)

$(MLIB):
	make -C lib

$(NAME):	 $(MLIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(MLIB) all

debug: CFLAGS += -ggdb3

debug: fclean $(MLIB) all

.PHONY:	all clean fclean re debug