/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_

	// INCLUDES

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

	// EXTERN

	extern  settings_t settings[];

	// DEFINES

	#define READ_SIZE 1

	// PROTOTYPES

	keys_t *init_keys();
	void free_tetris();
	layers_t *fill_layers();
	char *my_read();
	void display_layers();
	void display_tetris();
	piece_t *create_pieces();
	tetris_t *create_tetris();
	void move_tetris(tetris_t *tetris, char c);
	void display_keys();
	void display_options();
	void init_colors();
	int parsing_input();
	void set_key_quit();
	void set_key_pause();
	void set_map_size();
	void set_debug();
	void set_next();
	void set_key_drop();
	void set_key_turn();
	void set_key_right();
	void set_key_left();
	void set_level();
	void set_help();
	void set_level();
	void set_map_size();
	void set_next();
	char *parse_long_name();
	void display_error();
	int open_tetriminos();
#endif
