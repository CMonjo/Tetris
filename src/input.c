/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

void set_help(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	char *help = my_read("help/help.txt");

	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr(help);
	free(help);
	exit (0);
}

void set_debug(tetris_t *tetris, keys_t *keys)
{
	my_putstr("*** DEBUG MODE ***\n");
	display_keys(keys);
	display_options(tetris);
	my_putstr("\nPress any key to start Tetris");
	get_next_line(0);
}

void set_key_quit(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func key quit\n");
}

void set_key_pause(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func key pause\n");
}

void set_map_size(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func map size\n");
}

void set_next(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func set next\n");
}

void set_key_drop(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func key drop\n");
}

void set_key_turn(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func key turn\n");
}

void set_key_right(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func key right\n");
}

void set_key_left(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)index;
	my_putstr("func key left\n");
}

void set_level(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)keys;
	if (my_str_isnum(av[i + 1]) == 1)
		tetris->level = my_getnbr(av[i + 1]);
	if (tetris->level == 0)
		tetris->level = 1;
}

int parsing_input(tetris_t *tetris, keys_t *keys, char **av)
{
	int debug = 0;

	for (int i = 0; av[i] != NULL; i++) {
		for (int j = 0; j < 11; j++) {
			if (my_strcmp(av[i], settings[j].long_name) == 0
			|| my_strcmp(av[i], settings[j].short_name) == 0) {
				if (my_strcmp(av[i], "-D") == 0 ||
				my_strcmp(av[i], "--debug") == 0)
					debug = 1;
				else
					settings[j].callback(tetris, keys, av, i);
			}
		}
	}
	if (debug != 0)
		set_debug(tetris, keys);
	else
		get_next_line(0);
	return (0);
}
