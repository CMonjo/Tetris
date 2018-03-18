##
## EPITECH PROJECT, 2017
## Project 2017
## File description:
## Build tetris binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/ -g3

LIB	=	-L lib/ -lmy -lncurses

SRC	=	src/main.c 				\
		src/create_tetris.c			\
		src/create_layers.c			\
		src/display_tetris.c			\
		src/display_layers.c			\
		src/tetris_move.c			\
		src/tetris_colide.c			\
		src/tetriminos.c			\
		src/init_color.c			\
		src/settings.c				\
		src/debug/input.c			\
		src/debug/display_debug_mode.c		\
		src/debug/set_options.c			\
		src/debug/set_keys_move.c		\
		src/debug/set_keys_option.c		\
		src/debug/tetrimino_error.c		\
		src/debug/tetrimino_folder_open.c	\
		src/free_tetris.c			\
		src/tetris_move_arrows.c		\
		src/loop.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bonus

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
