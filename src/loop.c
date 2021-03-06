/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void play_loop(layers_t *layers, tetris_t *tetris, int c)
{
	int lines = 20;

	if (tetris->y > 18)
		lines = tetris->y + 2;
	if (COLS > 46 + tetris->x + tetris->pieces[tetris->next]
	[tetris->n_rot].x && LINES >= lines) {
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
		refresh();
	}
	endwin();
}
