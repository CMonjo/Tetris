/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** display
*/

#include "main.h"

void display_tetriminos(tetris_t *t, int x, int y)
{
	for (int i = 0; i < t->pieces[t->actual][t->rot].y; i++) {
		for (int j = 0; j < t->pieces[t->actual][t->rot].x; j++) {
			attron(COLOR_PAIR(t->pieces[t->actual][t->rot].color));
			(t->pieces[t->actual][t->rot].piece[i][j] != 0)
			? mvprintw(1 + i + y, 41 + j + x, "*") : 0;
			attroff(COLOR_PAIR(t->pieces[t->actual][t->rot].color));
		}
	}
}

void display_next(tetris_t *t, layers_t *layers)
{
	if (t->display_next == 0)
		return;
	attron(COLOR_PAIR(my_getnbr(layers->next)));
	display_next_board(t, layers);
	attroff(COLOR_PAIR(my_getnbr(layers->next)));
	for (int i = 0; i < t->pieces[t->next][t->n_rot].y; i++) {
		for (int j = 0; j < t->pieces[t->next][t->n_rot].x; j++) {
			attron(COLOR_PAIR(t->pieces[t->next][t->n_rot].color));
			(t->pieces[t->next][t->n_rot].piece[i][j] != 0)
			? mvprintw(2	 + i, 67 + j, "*") : 0;
			attroff(COLOR_PAIR(t->pieces[t->next][t->n_rot].color));
		}
	}
}

void display_pieces(tetris_t *t)
{
	for (int i = 0; i < t->y; i++) {
		for (int j = 0; j < t->x; j++) {
			attron(COLOR_PAIR(t->board[i][j]));
			(t->board[i][j] != 0)
			? mvprintw(1 + i, 41 + j, "*") : 0;
			attroff(COLOR_PAIR(t->board[i][j]));
		}
	}
}
