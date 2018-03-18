/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void tetris_keys(tetris_t *tetris, int *x, int *y, int c)
{
	if (c < 258 || c > 261) {
		tetris->rot += (c == tetris->keys->n_turn[0]) ? 1 : 0;
		*y += (c == tetris->keys->n_drop[0]) ? 1 : 0;
		*x += (c == tetris->keys->n_right[0]) ? 1 : 0;
		*x -= (c == tetris->keys->n_left[0]) ? 1 : 0;
	} else {
		tetris_up_down(tetris, x, y, c);
		tetris_right_left(tetris, x, y, c);
	}
	tetris->rot = (tetris->rot > 3) ? 0 : tetris->rot;
}

void tetris_gravity(tetris_t *tetris, int *y)
{
	static double timer = 0;

	if (timer + 200000 / (tetris->level * 0.3) < clock()) {
		timer = clock();
		(*y)++;
	}
}

void fall_tetris(tetris_t *tetris, int line)
{
	for (int i = line; i > 1; i--) {
		for (int j = 0; j < tetris->x; j++)
			tetris->board[i][j] = tetris->board[i - 1][j];
	}
}

void breack_line(tetris_t *tetris)
{
	static int level = 0;

	for (int i = 0, line = 0; i < tetris->y; i++, line = 0) {
		for (int j = 0; j < tetris->x; j++)
			line = (tetris->board[i][j] == 0) ? 1 : line;
		if (line == 0) {
			tetris->score += 100;
			fall_tetris(tetris, i);
			level ++;
		}
	} if (level >= 9) {
		tetris->level ++;
		level = 0;
	}
}

void move_tetris(tetris_t *tetris, int c)
{
	static int x = 0;
	static int y = 0;
	static int tmp = 0;

	x = (tmp == 0) ? tetris->x / 2 : x;
	tmp ++;
	tetris_gravity(tetris, &y);
	tetris_keys(tetris, &x, &y, c);
	if (tetris_colide(tetris, &x, &y) == 1) {
		if (freeze_tetriminos(tetris, x, y) == 1)
			tetris->lose = 1;
		tetris->actual = tetris->next;
		tetris->next = rand() % tetris->tetriminos;
		tetris->rot = tetris->n_rot;
		tetris->n_rot = rand() % 4;
		x = tetris->x / 2;
		y = 0;
	}
	breack_line(tetris);
	display_tetriminos(tetris, x, y);
}
