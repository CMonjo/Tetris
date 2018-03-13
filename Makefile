##
## EPITECH PROJECT, 2017
## Project =pname=
## File description:
## Build =pname= binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/ -g3

LIB	=	-L lib/ -lmy -ltools -lncurses

SRC	=	src/main.c 			\
		src/create_tetris.c		\
		src/create_layers.c		\
		src/display.c			\
		src/move_tetris.c		\
		src/tetriminos.c		\
		src/settings.c			\
		src/input.c			\
		src/display_debug_mode.c	\
		src/set_options.c		\
		src/init_color.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/

re: fclean all
