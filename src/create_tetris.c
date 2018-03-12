/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

keys_t *init_keys(void)
{
	keys_t *keys = malloc(sizeof(keys_t));

	keys->quit = 'q';
	return (keys);
}

int **create_board(tetris_t *tetris)
{
	int **board = malloc(sizeof(int *) * tetris->y);

	for (int i = 0; i < tetris->y; i++) {
		board[i] = malloc(sizeof(int) * tetris->x);
		for (int j = 0; j < tetris->x; j++)
			board[i][j] = 0;
	}
	return (board);
}

tetris_t *create_tetris(void)
{
	tetris_t *tetris = malloc(sizeof(tetris_t));

	if (!tetris)
		return (NULL);
	tetris->pieces = create_pieces();
	tetris->x = 20;
	tetris->y = 20;
	tetris->board = create_board(tetris);
	tetris->pos = 1;
	tetris->actual = rand() % 6;
	tetris->next = rand() % 6;
	if (!tetris->pieces)
		return (NULL);
	return (tetris);
}
