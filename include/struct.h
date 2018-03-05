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
	} layers_t;

	typedef struct piece_s {
		int x;
		int y;
		int color;
		char **piece;
	} piece_t;

	typedef struct tetris_s {
		piece_t *pieces;
		char **map;
		int x;
		int y;
		int pos;
		int next;
	} tetris_t;

#endif
