/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

char **create_map(tetris_t *tetris)
{
	char **map = malloc(sizeof(char *) * (tetris->y + 1));

	for (int i = 0; i < tetris->y; i++) {
		map[i] = malloc(sizeof(char) * (tetris->x + 1));
		for (int j = 0; j < tetris->x; j++)
			map[i][j] = ' ';
		map[i][tetris->x] = '\0';
	}
	map[tetris->y] = NULL;
	return (map);
}

tetris_t *create_tetris(void)
{
	tetris_t *tetris = malloc(sizeof(tetris_t));

	if (!tetris)
		return (NULL);
	tetris->pieces = create_pieces();
	tetris->x = 20;
	tetris->y = 20;
	tetris->map = create_map(tetris);
	tetris->pos = 1;
	tetris->next = rand() % 6;
	if (!tetris->pieces)
		return (NULL);
	return (tetris);
}
