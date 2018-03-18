/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** display
*/

#include "main.h"

int get_2_nbr(char *str)
{
	return (((str[4] - '0') * 10) + str[5] - '0');
}

void display_play_board(tetris_t *t, layers_t *layers)
{
	char str[2];

	str[1] = '\0';
	str[0] = layers->board[0];
	mvprintw(0, 40, str);
	mvprintw(0 + t->y + 1, 41 + t->x, str);
	str[0] = layers->board[1];
	for (int i = 0; i < t->x; i++) {
		mvprintw(0, 41 + i, str);
		mvprintw(0 + t->y + 1, 41 + i, str);
	}
	str[0] = layers->board[2];
	mvprintw(0, 41 + t->x, str);
	mvprintw(0 + t->y + 1, 40, str);
	str[0] = layers->board[3];
	for (int i = 0; i < t->y; i++) {
		mvprintw(1 + i, 40, str);
		mvprintw(1 + i, 41 + t->x, str);
	}
}

void display_layers(layers_t *layers, tetris_t *tetris)
{
	for (int i = 0; layers->art[i + 1]; i++)
		mvprintw(19 + i, 24, layers->art[i]);
	for (int i = 0; layers->name[i + 1]; i++)
		mvprintw(1 + i, 2, layers->name[i]);
	attron(COLOR_PAIR(get_2_nbr(layers->board)));
	display_play_board(tetris, layers);
	attroff(COLOR_PAIR(get_2_nbr(layers->board)));
	attron(COLOR_PAIR(my_getnbr(layers->score[11])));
	for (int i = 0; layers->score[i + 2]; i++)
		mvprintw(9 + i, 6, layers->score[i]);
	attroff(COLOR_PAIR(my_getnbr(layers->score[11])));
	attron(COLOR_PAIR(my_getnbr(layers->text[7])));
	for (int i = 0; layers->text[i + 2]; i++)
		mvprintw(11 + i, 7, layers->text[i]);
	attroff(COLOR_PAIR(my_getnbr(layers->text[7])));
}

void display_next_board(tetris_t *t, layers_t *layers)
{
	char str[2] = "\0\0";
	int nxt = 44 + t->x;

	str[0] = layers->next[0];
	mvprintw(1, nxt - 1, str);
	mvprintw(1 + t->pieces[t->next][t->n_rot].y + 1,
	nxt + 2 + t->pieces[t->next][t->n_rot].x, str);
	str[0] = layers->next[1];
	for (int i = 0; i < t->pieces[t->next][t->n_rot].x + 2; i++) {
		mvprintw(1, nxt + i, str);
		mvprintw(1 + t->pieces[t->next][t->n_rot].y + 1, nxt + i, str);
	}
	str[0] = layers->next[2];
	mvprintw(1, nxt + 2 + t->pieces[t->next][t->n_rot].x, str);
	mvprintw(1 + t->pieces[t->next][t->n_rot].y + 1, nxt - 1, str);
	str[0] = layers->next[3];
	for (int i = 0; i < t->pieces[t->next][t->n_rot].y; i++) {
		mvprintw(2 + i, nxt - 1, str);
		mvprintw(2 + i, nxt + 2 + t->pieces[t->next][t->n_rot].x, str);
	}
}
