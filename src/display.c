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

void display_pieces(piece_t *pieces)
{
	for (int i = 0; pieces->piece[i]; i++)
		mvprintw(5 + i, 50, pieces->piece[i]);
}

void display_tetris(layers_t *layers, piece_t *pieces)
{
	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	for (int c = 0; c != 'e';) {
		clear();
		display_layers(layers);
		display_pieces(pieces);
		refresh();
		c = wgetch(stdscr);
	}
	endwin();
}
