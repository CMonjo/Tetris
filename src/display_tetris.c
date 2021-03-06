/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** display
*/

#include "main.h"

void display_timer(tetris_t *tetris)
{
	char *str;

	tetris->timer = clock() / CLOCKS_PER_SEC;
	str = i_to_a(tetris->timer / 60);
	if (tetris->timer / 60 > 9)
		mvprintw(17, 26, str);
	else {
		mvprintw(17, 26, "0");
		mvprintw(17, 27, str);
	}
	free(str);
	mvprintw(17, 28, ":");
	str = i_to_a(tetris->timer % 60);
	if (tetris->timer % 60 > 9)
		mvprintw(17, 29, str);
	else {
		mvprintw(17, 29, "0");
		mvprintw(17, 30, str);
	}
	free(str);
}

void display_info(tetris_t *tetris)
{
	char *str;

	mvprintw(11, 26, tetris->high);
	str = i_to_a(tetris->score);
	mvprintw(12, 26, str);
	free(str);
	str = i_to_a(tetris->lines);
	mvprintw(14, 26, str);
	free(str);
	str = i_to_a(tetris->level);
	mvprintw(15, 26, str);
	free(str);
	display_timer(tetris);
}

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
	attron(COLOR_PAIR(get_2_nbr(layers->next)));
	mvprintw(0, 43 + t->x, "Next");
	display_next_board(t, layers);
	attroff(COLOR_PAIR(get_2_nbr(layers->next)));
	for (int i = 0; i < t->pieces[t->next][t->n_rot].y; i++) {
		for (int j = 0; j < t->pieces[t->next][t->n_rot].x; j++) {
			attron(COLOR_PAIR(t->pieces[t->next][t->n_rot].color));
			(t->pieces[t->next][t->n_rot].piece[i][j] != 0)
			? mvprintw(2 + i, 45 + t->x + j, "*") : 0;
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
