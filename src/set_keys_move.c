/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

void set_key_drop(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)tetris;
	// VERIF MALLOC TMP
	if (my_strncmp(av[i], settings[1].long_name, settings[1].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL)
			keys->n_drop = tmp;
	} else if (av[i + 1] != NULL)
		keys->n_drop = av[i + 1];
	if (keys->n_drop == NULL)
		keys->n_drop = "";
}

void set_key_turn(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)i;
	my_putstr("func key turn\n");
}

void set_key_right(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)i;
	my_putstr("func key right\n");
}

void set_key_left(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)i;
	my_putstr("func key left\n");
}
