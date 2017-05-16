##
## Makefile for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Wed May 10 13:55:08 2017 Martin Januario
## Last update Tue May 16 13:00:53 2017 Martin Januario
##

SRC	=	src/main.c		\
		src/found_term.c	\
		src/check_is_key.c	\
		src/reset_line.c	\
		src/is_a_key.c		\
		src/start_end.c		\
		src/ini_keys.c

BASICS	=	basics/my_free.c	\
		basics/my_realloc.c	\
		basics/my_putstr.c	\
		basics/my_strlen.c

OBJ	=	$(SRC:.c=.o)		\
		$(BASICS:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include/

NAME	=	edit_line

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
