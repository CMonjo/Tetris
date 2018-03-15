/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

int set_key_drop(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], settings[5].long_name, settings[5].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_drop = tmp;
	}
	else if (my_strcmp(av[i], settings[5].short_name) == 0 && av[i + 1] != NULL) {
		keys->n_drop = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_turn(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], settings[4].long_name, settings[4].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_turn = tmp;
	}
	else if (my_strcmp(av[i], settings[4].short_name) == 0 && av[i + 1] != NULL) {
		keys->n_turn = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_right(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], settings[3].long_name, settings[3].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_right = tmp;
	}
	else if (my_strcmp(av[i], settings[3].short_name) == 0 && av[i + 1] != NULL) {
		keys->n_right = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_left(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], settings[2].long_name, settings[2].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_left = tmp;
	}
	else if (my_strcmp(av[i], settings[2].short_name) == 0 && av[i + 1] != NULL) {
		keys->n_left = av[i + 1];
		i++;
	}
	return (i);
}
