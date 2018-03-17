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

int set_help(tetris_t *tetris, char **av, int index)
{
	char *help = my_read("help/help.txt");

	(void)tetris;
	my_putstr("Usage: ");
	my_putstr(av[0]);
	my_putstr(" [options]\n");
	my_putstr(help);
	free(help);
	exit (index);
}

int parsing_loop(tetris_t *t, char **av, int i, int j)
{
	if (my_strcmp(av[i], stgs[j].short_name) == 0
	|| my_strncmp(av[i], stgs[j].long_name,
		stgs[j].size) == 0) {
		if (my_strcmp(av[i], "-D") == 0 ||
		my_strcmp(av[i], "--debug") == 0)
			t->keys->debug = 1;
		else {
			i = stgs[j].callback(t, av, i);
			t->keys->error_input = 1;
			t->keys->my_break = 1;
		}
		t->keys->error_input = 1;
	}
	return (i);
}

int parsing_input(tetris_t *t, char **av)
{
	for (int i = 1; av[i] != NULL; i++, t->keys->error_input = 0, t->keys->my_break = 0) {
		for (int j = 0; j < 11; j++) {
			i = parsing_loop(t, av, i, j);
			if (t->keys->my_break == 1)
				break;
		}
		t->keys->error_input == 0 ? display_error() : 0;
	}
	t->keys->debug != 0 ? set_debug(t) : 0;
	t->x > 100 ? t->x = 100 : 0;
	t->y > 100 ? t->y = 100 : 0;
	return (0);
}
