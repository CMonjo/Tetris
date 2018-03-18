##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Library my
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I ../../include/ -g3

SRC	=	my_strlen.c		\
		my_putstr.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_revstr.c		\
		my_strcat.c		\
		my_str_isnum.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strncmp.c		\
		my_getnbr.c		\
		get_next_line.c		\
		clear_space.c		\
		clear_tab.c		\
		my_str_array.c		\
		concat_paths.c		\
		i_to_a.c		\
		my_str_to_word_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
