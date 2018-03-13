##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Library my
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I ../../include/ -g3

SRC	=	my_getnbr.c	\
		my_putstr.c	\
		my_putchar.c	\
		my_putstr.c	\
		get_next_line.c	\
		my_put_nbr.c	\
		my_str_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../libtools.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
