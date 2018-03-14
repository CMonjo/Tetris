/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

int tetriminos_colide(tetris_t *trs, int *x, int *y)
{
	for (int i = 0, l = 0; i < trs->pieces[trs->actual].x; i++, l = 0) {
		for (int j = 0; j < trs->pieces[trs->actual].y; j++)
			l = (trs->pieces[trs->actual].piece[j][i] != 0) ? j : l;
		if (trs->board[*y + l][*x + i] != 0)
			return (1);
	}
	return (0);
}

int tetris_colide(tetris_t *tetris, int *x, int *y)
{
	if (*y + tetris->pieces[tetris->actual].y > tetris->y + 1)
		*y -= 1;
	if (*y + tetris->pieces[tetris->actual].y == tetris->y + 1)
		return (1);
	if (*x + tetris->pieces[tetris->actual].x >= tetris->x + 1)
		*x = *x - 1;
	if (*x < 0)
		*x = 0;
	if (tetriminos_colide(tetris, x, y) == 1)
		return (1);
	return (0);
}

void display_tetriminos(tetris_t *t, int x, int y)
{
	for (int i = 0; i < t->pieces[t->actual].y; i++) {
		for (int j = 0; j < t->pieces[t->actual].x; j++) {
			if (t->pieces[t->actual].piece[i][j] != 0) {
				attron(COLOR_PAIR(t->pieces[t->actual].color));
				mvprintw(1 + i + y, 41 + j + x, "*");
				attroff(COLOR_PAIR(t->pieces[t->actual].color));
			}
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

void tetris_gravity(int *y)
{
	static double timer = 0;

	if (timer + 100000 < clock()) {
		timer = clock();
		(*y)++;
	}
}

int freeze_tetriminos(tetris_t *tetris, int x, int y)
{
	for (int i = 0; i < tetris->pieces[tetris->actual].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->actual].x; j++) {
			if (y + i - 1 < 0)
				return (1);
			if (tetris->pieces[tetris->actual].piece[i][j] != 0)
				tetris->board[y + i - 1][x + j] = tetris->pieces[tetris->actual].piece[i][j];
		}
	}
	return (0);
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
		x = 8;
		y = 0;
	}
	display_tetriminos(tetris, x, y);
}
