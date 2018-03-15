/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

int set_key_quit(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], settings[6].long_name, settings[6].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_quit = tmp;
	}
	else if (my_strcmp(av[i], settings[6].short_name) == 0 && av[i + 1] != NULL) {
		keys->n_quit = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_pause(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], settings[7].long_name, settings[7].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_pause = tmp;
	}
	else if (my_strcmp(av[i], settings[7].short_name) == 0 && av[i + 1] != NULL) {
		keys->n_pause = av[i + 1];
		i++;
	}
	return (i);
}
