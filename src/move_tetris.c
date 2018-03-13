/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

int tetriminos_colide(tetris_t *tetris, int *x, int *y)
{
	for (int i = 0, line = 0; i < tetris->pieces[tetris->actual].x;
	i++, line = 0) {
		for (int j = 0; j < tetris->pieces[tetris->actual].y; j++)
			line = (tetris->pieces[tetris->actual].piece[j][i]
			!= 0) ? j : line;
		if (tetris->board[*y + line][*x + i] != 0)
			return (1);
	}
	return (0);
}

int tetris_colide(tetris_t *tetris, int *x, int *y)
{
	if (*y + tetris->pieces[tetris->actual].y > tetris->y)
		*y -= 1;
	if (*y + tetris->pieces[tetris->actual].y == tetris->y + 1)
		return (1);
	if (*x + tetris->pieces[tetris->actual].x == tetris->x + 1)
		*x = *x - 1;
	if (*x < 0)
		*x = 0;
	if (tetriminos_colide(tetris, x, y) == 1)
		return (1);
	return (0);
}

void clear_tetriminos(tetris_t *tetris, int o_x, int o_y)
{
	for (int i = 0; i < tetris->pieces[tetris->actual].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->actual].x; j++)
			tetris->board[o_y + i][o_x + j] = 0;
	}
}

void display_tetriminos(tetris_t *tetris, int x, int y)
{
	for (int i = 0; i < tetris->pieces[tetris->actual].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->actual].x; j++) {
			tetris->board[y + i][x + j] =
			(tetris->pieces[tetris->actual].piece[i][j] != 0)
			? tetris->pieces[tetris->actual].color
			: tetris->board[y + i][x + j];
		}
	}
}

void tetris_keys(int *x, int *y, char c)
{
	*y -= (c == 'z') ? 1 : 0;
	*y += (c == 's') ? 1 : 0;
	*x += (c == 'd') ? 1 : 0;
	*x -= (c == 'q') ? 1 : 0;
}

void move_tetris(tetris_t *tetris, char c)
{
	static int x = 8;
	static int y = 0;
	static int o_x = 0;
	static int o_y = 0;

	o_x = x;
	o_y = y;
	y++;
	tetris_keys(&x, &y, c);
	if (tetris_colide(tetris, &x, &y) == 1) {
		tetris->actual = tetris->next;
		tetris->next = rand() % 6;
		x = 8;
		y = 0;
		o_x = 0;
		o_y = 0;
	}
	clear_tetriminos(tetris, o_x, o_y);
	display_tetriminos(tetris, x, y);
}
