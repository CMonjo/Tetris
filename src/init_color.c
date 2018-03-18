/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** display
*/

#include "main.h"

void init_colors(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(7, COLOR_CYAN, COLOR_CYAN);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
	init_pair(11, COLOR_RED, COLOR_BLACK);
	init_pair(12, COLOR_GREEN, COLOR_BLACK);
	init_pair(13, COLOR_YELLOW, COLOR_BLACK);
	init_pair(14, COLOR_BLUE, COLOR_BLACK);
	init_pair(15, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(16, COLOR_CYAN, COLOR_BLACK);
}
