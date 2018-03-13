/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

void set_level(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)keys;
	if (my_strncmp(av[i], settings[1].long_name, settings[1].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		if (tmp != NULL && my_str_isnum(tmp) == 1)
			tetris->level = my_getnbr(tmp);
	}
	else if (my_str_isnum(av[i + 1]) == 1)
		tetris->level = my_getnbr(av[i + 1]);
	if (tetris->level == 0)
		tetris->level = 1;
}

void set_next(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)keys;
	(void)av;
	(void)i;
	tetris->display_next = 0;
}

void set_map_size(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	(void)tetris;
	(void)keys;
	(void)av;
	(void)i;
	my_putstr("func map size\n");
}
