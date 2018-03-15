/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

void display_error(void)
{
	my_putstr("Error input\n");
	exit (84);
}

char *parse_long_name(char *arg, char *tmp)
{
	int j = 0;
	int k = 0;
	int bracket = 0;

	for (j = 0; arg[j] != '='; j++);
	if (arg[j + 1] == '{') {
		j++;
		bracket++;
	}
	for (k = 0, j++; arg[j] != '\0'; j++, k++)
		tmp[k] = arg[j];
	if (bracket != 0 && arg[j - 1] != '}')
		return (NULL);
	else if (bracket != 0)
		tmp[k - 1] = '\0';
	return (tmp);
}

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

void init_n_keys(keys_t *keys)
{
	keys->n_left = "ˆEOD";
	keys->n_right = "ˆEOC";
	keys->n_turn = "ˆEOA";
	keys->n_drop = "ˆEOB";
	keys->n_quit = "q";
	keys->n_pause = "(space)";
}

void set_debug(tetris_t *tetris, keys_t *keys)
{
	init_n_keys(keys);
	my_putstr("*** DEBUG MODE ***\n");
	display_keys(keys);
	display_options(tetris);
	open_tetriminos();
	my_putstr("Press any key to start Tetris");
	get_next_line(0);
}

int parsing_input(tetris_t *tetris, keys_t *keys, char **av)
{
	int debug = 0;

	for (int i = 0; av[i] != NULL; i++) {
		for (int j = 0; j < 11; j++) {
			if (my_strcmp(av[i], settings[j].short_name) == 0
			|| my_strncmp(av[i], settings[j].long_name,
				settings[j].size) == 0) {
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
	return (0);
}
