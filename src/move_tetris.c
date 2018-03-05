/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void move_tetris(tetris_t *tetris, char c)
{
	static int x = 9;
	static int y = 0;
	static int o_x = 0;
	static int o_y = 0;

	for (int i = 0; i < tetris->pieces[tetris->next].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->next].x; j++)
			tetris->map[o_y + i][o_x + j] = ' ';
	}
	for (int i = 0; i < tetris->pieces[tetris->next].y; i++) {
		for (int j = 0; j < tetris->pieces[tetris->next].x; j++)
			tetris->map[y + i][x + j] =\
			tetris->pieces[tetris->next].piece[i][0];
	}
	o_x = x;
	o_y = y;
	y -= (c == 'z') ? 1 : 0;
	y += (c == 's') ? 1 : 0;
	x += (c == 'd') ? 1 : 0;
	x -= (c == 'q') ? 1 : 0;
}
