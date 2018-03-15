/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

	typedef struct layers_s {
		char **name;
		char **board;
		char **score;
		char **text;
		char **next;
		char **art;
		char **loooseeer;
	} layers_t;

	typedef struct settings_s {
		char *short_name;
		char *long_name;
		int size;
		int (*callback)();
	} settings_t;

	typedef struct piece_s {
		int x;
		int y;
		int color;
		int **piece;
	} piece_t;

	typedef struct keys_s {
		int left;
		char *n_left;
		int right;
		char *n_right;
		int turn;
		char *n_turn;
		int drop;
		char *n_drop;
		int quit;
		char *n_quit;
		int pause;
		char *n_pause;
	} keys_t;

	typedef struct tetris_s {
		piece_t **pieces;
		int **board;
		int x;
		int y;
		int tetriminos;
		int rot;
		int n_rot;
		int lose;
		int actual;
		int next;
		int display_next;
		char *high;
		int score;
		int lines;
		int level;
		int timer;
	} tetris_t;

#endif
