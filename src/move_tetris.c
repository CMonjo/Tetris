/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

int tetris_colide(tetris_t *tetris, int *x, int *y)
{
	if (*y + tetris->pieces[tetris->next].y == tetris->y + 1)
		return (1);
	if (*x + tetris->pieces[tetris->next].x == tetris->x + 1)
		*x = *x - 1;
	else if (*x < 0)
		*x = 0;
	return (0);
}

void move_tetris(tetris_t *tetris, char c)
{
	static int x = 9;
	static int y = 0;
	static int o_x = 0;
	static int o_y = 0;

	for (int i = 0; i < tetris->pieces[tetris->next].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->next].x; j++)
			tetris->board[o_y + i][o_x + j] = 0;
	}
	for (int i = 0; i < tetris->pieces[tetris->next].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->next].x; j++)
			tetris->board[y + i][x + j] =\
			tetris->pieces[tetris->next].color;
	}
	o_x = x;
	o_y = y;
	y -= (c == 'z') ? 1 : 0;
	y += (c == 's') ? 1 : 0;
	x += (c == 'd') ? 1 : 0;
	x -= (c == 'q') ? 1 : 0;
	if (tetris_colide(tetris, &x, &y) == 1) {
		tetris->next = rand() % 6;
		x = 0;
		y = 0;
		o_x = 0;
		o_y = 0;
	}
}
