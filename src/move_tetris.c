/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

// for (int i = 0; i < tetris->pieces[tetris->actual].y; i++) {
// 	for (int j = 0; j < tetris->pieces[tetris->actual].x; j++) {
// 		if (tetris->pieces[tetris->actual].piece[i][j] != 0 &&
// 		tetris->board[*y + i + 1][*x + j] != 0)
// 			return (1);
// 	}
// }

int tetris_colide(tetris_t *tetris, int reverse, int *x, int *y)
{
	if (reverse == 0) {
		if (*y + tetris->pieces[tetris->actual].y == tetris->y + 1)
			return (1);
		if (*x + tetris->pieces[tetris->actual].x == tetris->x + 1)
			*x = *x - 1;
	} else {
		if (*y + tetris->pieces[tetris->actual].x == tetris->y + 1)
			return (1);
		if (*x + tetris->pieces[tetris->actual].y == tetris->x + 1)
			*x = *x - 1;
	}
	if (*x < 0)
		*x = 0;
	return (0);
}

void clear_tetriminos(tetris_t *tetris, int reverse, int o_x, int o_y)
{
	if (reverse == 0) {
		for (int i = 0; i < tetris->pieces[tetris->actual].y; i++) {
			for (int j = 0; j < tetris->pieces[tetris->actual].x; j++)
				tetris->board[o_y + i][o_x + j] = 0;
		}
	} else {
		for (int i = 0; i < tetris->pieces[tetris->actual].x; i++) {
			for (int j = 0; j < tetris->pieces[tetris->actual].y; j++)
				tetris->board[o_y + i][o_x + j] = 0;
		}
	}
}

void display_tetriminos(tetris_t *tetris, int reverse, int x, int y)
{
	if (reverse == 0) {
		for (int i = 0; i < tetris->pieces[tetris->actual].y; i++) {
			for (int j = 0; j < tetris->pieces[tetris->actual].x; j++) {
				tetris->board[y + i][x + j] =
				(tetris->pieces[tetris->actual].piece[i][j] != 0)
				? tetris->pieces[tetris->actual].color
				: tetris->board[y + i][x + j];
			}
		}
	} else {
		for (int i = 0; i < tetris->pieces[tetris->actual].x; i++) {
			for (int j = 0; j < tetris->pieces[tetris->actual].y; j++) {
				tetris->board[y + i][x + j] =
				(tetris->pieces[tetris->actual].piece[j][i] != 0)
				? tetris->pieces[tetris->actual].color
				: tetris->board[y + i][x + j];
			}
		}
	}
}

void tetris_keys(int *reverse, int *x, int *y, char c)
{
	if (c == 'r') {
		if (*reverse == 0)
			*reverse = 1;
		else if (*reverse == 1)
			*reverse = 0;
	}
	*y -= (c == 'z') ? 1 : 0;
	*y += (c == 's') ? 1 : 0;
	*x += (c == 'd') ? 1 : 0;
	*x -= (c == 'q') ? 1 : 0;
}

void move_tetris(tetris_t *tetris, char c)
{
	static int reverse = 0;
	static int x = 8;
	static int y = 0;
	static int o_x = 0;
	static int o_y = 0;

	o_x = x;
	o_y = y;
	clear_tetriminos(tetris, reverse, o_x, o_y);
	tetris_keys(&reverse,&x, &y, c);
	if (tetris_colide(tetris, reverse, &x, &y) == 1) {
		tetris->actual = tetris->next;
		tetris->next = rand() % 6;
		reverse = 0;
		x = 8;
		y = 0;
		o_x = 0;
		o_y = 0;
	}
	display_tetriminos(tetris, reverse, x, y);
}
