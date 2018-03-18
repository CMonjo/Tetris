/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void end_loop(layers_t *layers, tetris_t *tetris)
{
	for (int c = 0; c != tetris->keys->n_quit[0];) {
		c = wgetch(stdscr);
		clear();
		for (int i = 0; layers->loooseeer[i + 1]; i++)
			mvprintw(1 + i, 2, layers->loooseeer[i]);
		refresh();
	}
}

void play_loop(layers_t *layers, tetris_t *tetris, int c)
{
	if (COLS > 45 + tetris->x + tetris->pieces[tetris->actual][tetris->rot].x && LINES >= 20) {
		display_layers(layers, tetris);
		display_next(tetris, layers);
		display_info(tetris);
		display_pieces(tetris);
		move_tetris(tetris, c);
	} else {
		mvprintw(LINES / 2, COLS / 2, "Resize");
	}
}

void game_loop(layers_t *layers, tetris_t *tetris)
{
	initscr();
	init_colors();
	curs_set(0);
	keypad(stdscr, TRUE);
	for (int c = 0; c != tetris->keys->n_quit[0] && tetris->lose == 0;) {
		timeout(0.5);
		c = wgetch(stdscr);
		clear();
		play_loop(layers, tetris, c);
		mvprintw(7, 0, i_to_a(COLS));
		mvprintw(8, 0, i_to_a(LINES));
		refresh();
	}
	end_loop(layers, tetris);
	endwin();
}
