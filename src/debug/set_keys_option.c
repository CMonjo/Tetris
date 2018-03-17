/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

int set_key_quit(tetris_t *t, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], stgs[6].long_name, stgs[6].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			t->keys->n_quit = tmp;
	}
	else if (my_strcmp(av[i], stgs[6].short_name) == 0 && av[i + 1] != NULL) {
		t->keys->n_quit = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_pause(tetris_t *t, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], stgs[7].long_name, stgs[7].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			t->keys->n_pause = tmp;
	}
	else if (my_strcmp(av[i], stgs[7].short_name) == 0 && av[i + 1] != NULL) {
		t->keys->n_pause = av[i + 1];
		i++;
	}
	return (i);
}
