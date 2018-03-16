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

	typedef struct stgs_s {
		char *short_name;
		char *long_name;
		int size;
		int (*callback)();
	} stgs_t;

	typedef struct piece_s {
		int x;
		int y;
		int color;
		int **piece;
	} piece_t;

	typedef struct keys_s {
		char *n_left;
		char *n_right;
		char *n_turn;
		char *n_drop;
		char *n_quit;
		char *n_pause;
		int debug;
		int error_input;
		int my_break;
	} keys_t;

	typedef struct tetris_s {
		piece_t **pieces;
		int **board;
		keys_t *keys;
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
