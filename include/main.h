/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/System/Vector2.h>
	#include <SFML/Audio.h>
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

	void free_tetris(layers_t *layers, tetris_t *tetris);
	layers_t *fill_layers(void);
	char *my_read(char *path);
	void display_layers(layers_t *layers);
	void display_tetris(layers_t *layers, tetris_t *tetris);
	piece_t *create_pieces(void);
	tetris_t *create_tetris(void);
	void move_tetris(tetris_t *tetris, char c);
	void init_colors(void);
#endif
