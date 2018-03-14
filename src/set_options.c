/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"

void set_level(tetris_t *tetris, keys_t *keys, char **av, int i)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));

	(void)keys;
	// VERIF MALLOC TMP
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
	char *tmp = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
	char **tab;
	int k = 0;

	(void)keys;
	// VERIF MALLOC TMP
	if (my_strncmp(av[i], settings[8].long_name, settings[8].size) == 0) {
		tmp = parse_long_name(av[i], tmp);
		tab = my_str_to_word_array(tmp, ',');
		for (; tab[k] != NULL; k++);
		if (k != 2)
			display_error();
		// ATTENTION SI C'EST PAS ECRIT ={"12,12"} ça ne marche pas
		if (tmp != NULL && my_str_isnum(tab[0]) == 1
		&& my_str_isnum(tab[1]) == 1) {
				tetris->x = my_getnbr(tab[0]);
				tetris->y = my_getnbr(tab[1]);
		} else
			display_error();
	}
}
