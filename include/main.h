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
	#include "struct.h"

	// EXTERN

	extern  stgs_t stgs[];

	// DEFINES

	#define READ_SIZE 1

	// PROTOTYPES

	void tetris_right_left();
	void tetris_up_down();
	int get_2_nbr();
	void free_tetris();
	void free_pieces();
	void free_layers();
	void display_next_board();
	void display_info();
	void display_pieces();
	void display_layers();
	void display_next();
	int **create_board();
	int freeze_tetriminos();
	int tetris_colide();
	int tetriminos_colide();
	void display_tetriminos();
	char *i_to_a();
	keys_t *init_keys();
	void free_tetris();
	layers_t *fill_layers();
	char *my_read();
	void display_layers();
	void game_loop();
	piece_t **create_pieces();
	tetris_t *create_tetris();
	void move_tetris();
	void display_keys();
	void display_options();
	void init_colors();
	int parsing_input();
	int set_key_quit();
	int set_key_pause();
	int set_map_size();
	int set_debug();
	int set_next();
	int set_key_drop();
	int set_key_turn();
	int set_key_right();
	int set_key_left();
	int set_level();
	int set_help();
	int set_level();
	int set_map_size();
	int set_next();
	char *parse_long_name();
	void display_error();
	void open_tetriminos();
	int called_tetrimino();
#endif
