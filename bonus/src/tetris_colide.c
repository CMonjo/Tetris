/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

int tetriminos_colide(tetris_t *t, int *x, int *y)
{
	for (int i = 0, k = 0; i < t->pieces[t->actual][t->rot].x;
	i++, k = 0) {
		for (int j = 0; j < t->pieces[t->actual][t->rot].y; j++) {
			k = (t->pieces[t->actual][t->rot].piece[j][i]
			!= 0) ? j : k;
		}
		if (t->board[*y + k][*x + i] != 0)
			return (1);
	}
	return (0);
}

int tetris_colide(tetris_t *t, int *x, int *y)
{
	(*y + t->pieces[t->actual][t->rot].y > t->y + 1) ? *y -= 1 : 0;
	if (*y + t->pieces[t->actual][t->rot].y == t->y + 1)
		return (1);
	(*x + t->pieces[t->actual][t->rot].x == t->x + 1) ? (*x)-- : 0;
	(*x < 0) ? (*x)++ : 0;
	if (tetriminos_colide(t, x, y) == 1)
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
