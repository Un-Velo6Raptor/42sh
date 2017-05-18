##
## Makefile for  in /home/januar_m/delivery/PSU/edit_line
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Wed May 17 15:32:34 2017 Martin Januario
## Last update Wed May 17 17:30:15 2017 Martin Januario
##

SRC	=	src/main.c			\
		src/ini_keys.c			\
		src/check_is_key.c		\
		src/basic_key.c			\
		src/key_del.c			\
		src/found_term.c

BASICS	=	basics/my_putstr.c		\
		basics/my_strlen.c

OBJ	=	$(SRC:.c=.o)			\
		$(BASICS:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include/

NAME	=	edit

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
