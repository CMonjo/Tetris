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

void display_info(tetris_t *tetris)
{
	char *str;

	mvprintw(11, 26, tetris->high);
	str = i_to_a(tetris->score);
	mvprintw(12, 26, str);
	str = i_to_a(tetris->lines);
	mvprintw(14, 26, str);
	str = i_to_a(tetris->level);
	mvprintw(15, 26, str);
	tetris->timer = clock() / CLOCKS_PER_SEC;
	str = i_to_a(tetris->timer);
	mvprintw(17, 26, str);
	free(str);
}

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
	mvprintw(0 + t->y + 1, 43 + t->x, str);
	str[0] = layers->board[1];
	for (int i = 0; i < t->x + 2; i++) {
		mvprintw(0, 41 + i, str);
		mvprintw(0 + t->y + 1, 41 + i, str);
	}
	str[0] = layers->board[2];
	mvprintw(0, 43 + t->x, str);
	mvprintw(0 + t->y + 1, 40, str);
	str[0] = layers->board[3];
	for (int i = 0; i < t->y; i++) {
		mvprintw(1 + i, 40, str);
		mvprintw(1 + i, 43 + t->x, str);
	}
}

void display_layers(layers_t *layers, tetris_t *tetris)
{
	for (int i = 0; layers->art[i + 1]; i++)
		mvprintw(19 + i, 24, layers->art[i]);
	for (int i = 0; layers->name[i + 1]; i++)
		mvprintw(1 + i, 2, layers->name[i]);
	attron(COLOR_PAIR(my_getnbr(layers->board)));
	display_play_board(tetris, layers);
	attroff(COLOR_PAIR(my_getnbr(layers->board)));
	for (int i = 0; layers->score[i + 1]; i++)
		mvprintw(9 + i, 6, layers->score[i]);
	for (int i = 0; layers->text[i + 1]; i++)
		mvprintw(11 + i, 7, layers->text[i]);
}

void display_next_board(tetris_t *t, layers_t *layers)
{
	char str[2];

	str[1] = '\0';
	str[0] = layers->next[0];
	mvprintw(1, 65, str);
	mvprintw(1 + t->pieces[t->next][t->n_rot].y + 1,
	68 + t->pieces[t->next][t->n_rot].x, str);
	str[0] = layers->next[1];
	for (int i = 0; i < t->pieces[t->next][t->n_rot].x + 2; i++) {
		mvprintw(1, 66 + i, str);
		mvprintw(1 + t->pieces[t->next][t->n_rot].y + 1, 66 + i, str);
	}
	str[0] = layers->next[2];
	mvprintw(1, 68 + t->pieces[t->next][t->n_rot].x, str);
	mvprintw(1 + t->pieces[t->next][t->n_rot].y + 1, 65, str);
	str[0] = layers->next[3];
	for (int i = 0; i < t->pieces[t->next][t->n_rot].y; i++) {
		mvprintw(2 + i, 65, str);
		mvprintw(2 + i, 68 + t->pieces[t->next][t->n_rot].x, str);
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

void display_tetris(layers_t *layers, tetris_t *tetris)
{
	initscr();
	init_colors();
	curs_set(0);
	keypad(stdscr, TRUE);
	for (char c = 0; c != tetris->keys->n_quit[0] && tetris->lose == 0;) {
		timeout(0.5);
		c = wgetch(stdscr);
		clear();
		display_layers(layers, tetris);
		display_next(tetris, layers);
		display_info(tetris);
		display_pieces(tetris);
		move_tetris(tetris, c);
		refresh();
	} for (int c = 0; c != tetris->keys->n_quit[0];) {
		c = wgetch(stdscr);
		clear();
		for (int i = 0; layers->loooseeer[i + 1]; i++)
			mvprintw(1 + i, 2, layers->loooseeer[i]);
		refresh();
	}
	endwin();
}
