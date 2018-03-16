/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

int tetriminos_colide(tetris_t *t, int *x, int *y)
{
	for (int i = 0, l = 0; i < t->pieces[t->actual][t->rot].x;
	i++, l = 0) {
		for (int j = 0; j < t->pieces[t->actual][t->rot].y; j++) {
			l = (t->pieces[t->actual][t->rot].piece[j][i]
			!= 0) ? j : l;
		}
		if (t->board[*y + l][*x + i] != 0)
			return (1);
	}
	return (0);
}

int y_colide(tetris_t *t, int *y)
{
	if (*y + t->pieces[t->actual][t->rot].y > t->y + 1)
		*y -= 1;
	if (*y + t->pieces[t->actual][t->rot].y == t->y + 1)
		return (1);
	return (0);
}

void x_colide(tetris_t *t, int *x, int *y)
{
	if (*x + t->pieces[t->actual][t->rot].x == t->x + 1)
		(*x)--;
	if (*x < 0)
		(*x)++;
	// for (int i = 0, col = 0; i < t->pieces[t->actual][t->rot].y; i++, col++) {
	// 	for (int j = 0; j < t->pieces[t->actual][t->rot].x; j++) {
	// 		col = (t->pieces[t->actual][t->rot].piece[i][j] != 0)
	// 		? j : col;
	// 	}
	// 	if (*x + col < t->x && t->board[*y + i][*x + col] != 0) {
	// 		(*x)--;
	// 		return;
	// 	}
	// }
}


int tetris_colide(tetris_t *tetris, int *x, int *y)
{
	if (y_colide(tetris, y) == 1)
		return (1);
	x_colide(tetris, x, y);
	if (tetriminos_colide(tetris, x, y) == 1)
		return (1);
	return (0);
}

int freeeze_tetris(tetris_t *t, int x, int y, int i)
{
	for (int j = 0; j < t->pieces[t->actual][t->rot].x; j++) {
		if (y + i - 1 < 0)
			return (1);
		if (t->pieces[t->actual][t->rot].piece[i][j] != 0) {
			t->board[y + i - 1][x + j] =
			t->pieces[t->actual][t->rot].piece[i][j];
		}
	}
	return (0);
}

int freeze_tetriminos(tetris_t *t, int x, int y)
{
	for (int i = 0; i < t->pieces[t->actual][t->rot].y; i++) {
		if (freeeze_tetris(t, x, y, i) == 1)
			return (1);
	}
	return (0);
}
