/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** display
*/

#include "main.h"

void display_layers(layers_t *layers)
{
	attron(COLOR_PAIR(0));
	for (int i = 0; layers->penis[i + 1]; i++)
		mvprintw(19 + i, 24, layers->penis[i]);
	for (int i = 0; layers->name[i + 1]; i++)
		mvprintw(1 + i, 2, layers->name[i]);
	for (int i = 0; layers->board[i + 1]; i++)
		mvprintw(i, 40, layers->board[i]);
	for (int i = 0; layers->score[i + 1]; i++)
		mvprintw(9 + i, 6, layers->score[i]);
	for (int i = 0; layers->text[i + 1]; i++)
		mvprintw(11 + i, 7, layers->text[i]);
	for (int i = 0; layers->next[i + 1]; i++)
		mvprintw(1 + i, 65, layers->next[i]);
	attroff(COLOR_PAIR(0));
}

void display_pieces(tetris_t *tetris)
{
	for (int i = 0; i < tetris->pieces[tetris->next].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->next].x; j++) {
			if (tetris->pieces[tetris->next].piece[i][j] != 0) {
				attron(COLOR_PAIR(tetris->pieces[tetris->next].color));
				mvprintw(2 + i, 67 + j, "*");
				attroff(COLOR_PAIR(tetris->pieces[tetris->next].color));
			}
			else
				mvprintw(2 + i, 67 + j, " ");
		}
	} for (int i = 0; i < tetris->y; i++) {
		for (int j = 0; j < tetris->x; j++) {
			if (tetris->board[i][j] == 0)
				mvprintw(1 + i, 41 + j, " ");
			else {
				attron(COLOR_PAIR(tetris->board[i][j]));
				mvprintw(1 + i, 41 + j, "*");
				attroff(COLOR_PAIR(tetris->board[i][j]));
			}
		}
	}
}

void display_tetris(layers_t *layers, tetris_t *tetris, keys_t *keys)
{
	initscr();
	init_colors();
	curs_set(0);
	keypad(stdscr, TRUE);
	for (int c = 0; c != 'e';) {
		clear();
		display_layers(layers);
		display_pieces(tetris);
		refresh();
		timeout(500);
		c = wgetch(stdscr);
		move_tetris(tetris, c);
	}
	endwin();
}
