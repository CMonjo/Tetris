/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

int set_key_drop(tetris_t *t, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], stgs[5].long_name, stgs[5].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			t->keys->n_drop = tmp;
	}
	else if (my_strcmp(av[i], stgs[5].short_name) == 0 && av[i + 1] != NULL) {
		t->keys->n_drop = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_turn(tetris_t *t, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], stgs[4].long_name, stgs[4].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			t->keys->n_turn = tmp;
	}
	else if (my_strcmp(av[i], stgs[4].short_name) == 0 && av[i + 1] != NULL) {
		t->keys->n_turn = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_right(tetris_t *t, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], stgs[3].long_name, stgs[3].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			t->keys->n_right = tmp;
	}
	else if (my_strcmp(av[i], stgs[3].short_name) == 0 && av[i + 1] != NULL) {
		t->keys->n_right = av[i + 1];
		i++;
	}
	return (i);
}

int set_key_left(tetris_t *t, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	if (tmp == NULL)
		return (i);
	if (my_strncmp(av[i], stgs[2].long_name, stgs[2].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			t->keys->n_left = tmp;
	}
	else if (my_strcmp(av[i], stgs[2].short_name) == 0 && av[i + 1] != NULL) {
		t->keys->n_left = av[i + 1];
		i++;
	}
	return (i);
}
