/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

int tetriminos_colide(tetris_t *trs, int *x, int *y)
{
	for (int i = 0, l = 0; i < trs->pieces[trs->actual][trs->rot].x;
	i++, l = 0) {
		for (int j = 0; j < trs->pieces[trs->actual][trs->rot].y; j++) {
			l = (trs->pieces[trs->actual][trs->rot].piece[j][i]
			!= 0) ? j : l;
		}
		if (trs->board[*y + l][*x + i] != 0)
			return (1);
	}
	return (0);
}

int tetris_colide(tetris_t *tetris, int *x, int *y)
{
	if (*y + tetris->pieces[tetris->actual][tetris->rot].y > tetris->y + 1)
		*y -= 1;
	if (*y + tetris->pieces[tetris->actual][tetris->rot].y == tetris->y + 1)
		return (1);
	if (*x + tetris->pieces[tetris->actual][tetris->rot].x == tetris->x + 1)
		(*x)--;
	if (*x < 0)
		(*x)++;
	if (tetriminos_colide(tetris, x, y) == 1)
		return (1);
	return (0);
}

int freeze_tetriminos(tetris_t *t, int x, int y)
{
	for (int i = 0; i < t->pieces[t->actual][t->rot].y; i++) {
		for (int j = 0; j < t->pieces[t->actual][t->rot].x; j++) {
			if (y + i - 1 < 0)
				return (1);
			if (t->pieces[t->actual][t->rot].piece[i][j] != 0)
				t->board[y + i - 1][x + j] =
				t->pieces[t->actual][t->rot].piece[i][j];
		}
	}
	return (0);
}
