/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** display
*/

#include "main.h"

void display_layers(layers_t *layers)
{
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
}

void display_pieces(tetris_t *tetris)
{
	for (int i = 0; tetris->pieces[tetris->next].piece[i]; i++)
		mvprintw(2 + i, 67, tetris->pieces[tetris->next].piece[i]);
	for (int i = 0; tetris->map[i]; i++)
		mvprintw(1 + i, 41, tetris->map[i]);
}

void display_tetris(layers_t *layers, tetris_t *tetris)
{
	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	for (int c = 0; c != 'e';) {
		clear();
		display_layers(layers);
		display_pieces(tetris);
		refresh();
		c = wgetch(stdscr);
		move_tetris(tetris, c);
	}
	endwin();
}
