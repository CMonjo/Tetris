/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void tetris_keys(int *x, int *y, char c)
{
	*y -= (c == 'z') ? 1 : 0;
	*y += (c == 's') ? 1 : 0;
	*x += (c == 'd') ? 1 : 0;
	*x -= (c == 'q') ? 1 : 0;
}

void tetris_gravity(int *y)
{
	static double timer = 0;

	if (timer + 300000 < clock()) {
		timer = clock();
		(*y)++;
	}
}

void fall_tetris(tetris_t *tetris, int line)
{
	for (int i = 1; i < line; i++) {
		for (int j = 0; j < tetris->x; j++)
			tetris->board[i + 1][j] = tetris->board[i][j];
	}
}

void breack_line(tetris_t *tetris)
{
	for (int i = 0, line = 0; i < tetris->y; i++, line = 0) {
		for (int j = 0; j < tetris->x; j++)
			line = (tetris->board[i][j] == 0) ? 1 : line;
		if (line == 0) {
			tetris->score += 100;
			fall_tetris(tetris, i);
		}
	}
}

void move_tetris(tetris_t *tetris, char c)
{
	static int x = 8;
	static int y = 0;

	tetris_gravity(&y);
	tetris_keys(&x, &y, c);
	if (tetris_colide(tetris, &x, &y) == 1) {
		if (freeze_tetriminos(tetris, x, y) == 1)
			tetris->lose = 1;
		tetris->actual = tetris->next;
		tetris->next = rand() % tetris->tetriminos;
		tetris->rot = tetris->n_rot;
		tetris->n_rot = rand() % 4;
		x = 8;
		y = 0;
	}
	breack_line(tetris);
	display_tetriminos(tetris, x, y);
}
