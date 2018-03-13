/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <ncurses.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <math.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <time.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <fcntl.h>
	#include "my.h"
	#include "tools.h"
	#include "struct.h"

	extern  settings_t settings[];

	keys_t *init_keys(void);
	void free_tetris(layers_t *layers, tetris_t *tetris);
	layers_t *fill_layers(void);
	char *my_read(char *path);
	void display_layers(layers_t *layers);
	void display_tetris(layers_t *layers, tetris_t *tetris, keys_t *keys);
	piece_t *create_pieces(void);
	tetris_t *create_tetris(void);
	void move_tetris(tetris_t *tetris, char c);
	void init_colors(void);
	int parsing_input(int ac, char **av, keys_t *keys);
	void set_key_quit(void);
	void set_key_pause(void);
	void set_map_size(void);
	void set_debug(void);
	void set_next(void);
	void set_key_drop(void);
	void set_key_turn(void);
	void set_key_right(void);
	void set_key_left(void);
	void set_level(void);
	void set_help(void);

#endif
