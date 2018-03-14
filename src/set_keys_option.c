/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

void set_key_quit(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)i;
	my_putstr("func key quit\n");
}

void set_key_pause(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)i;
	my_putstr("func key pause\n");
}
