/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

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
		k -= 1;
	tmp[k] = '\0';
	return (tmp);
}

int set_help(tetris_t *tetris, keys_t *keys, char **av, int index)
{
	char *help = my_read("help/help.txt");

	(void)tetris;
	(void)keys;
	my_putstr("Usage: ");
	my_putstr(av[0]);
	my_putstr(" [options]\n");
	my_putstr(help);
	free(help);
	exit (index);
}

int parsing_input(tetris_t *tetris, keys_t *keys, char **av)
{
	int debug = 0;
	int error_input = 0;

	for (int i = 1; av[i] != NULL; i++, error_input = 0) {
		for (int j = 0; j < 11; j++) {
			if (my_strcmp(av[i], stgs[j].short_name) == 0
			|| my_strncmp(av[i], stgs[j].long_name,
				stgs[j].size) == 0) {
				if (my_strcmp(av[i], "-D") == 0 ||
				my_strcmp(av[i], "--debug") == 0)
					debug = 1;
				else {
					i = stgs[j].callback(tetris, keys, av, i);
					error_input = 1;
					break;
				}
				error_input = 1;
			}
		}
		if (error_input == 0)
			display_error();
	}
	if (debug != 0)
		set_debug(tetris, keys);
	return (0);
}
