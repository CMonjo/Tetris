/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Debug mode file
*/

#include "main.h"


void set_key_quit(void)
{
	my_putstr("func key quit\n");
}

void set_key_pause(void)
{
	my_putstr("func key pause\n");
}

void set_map_size(void)
{
	my_putstr("func map size\n");
}

void set_next(void)
{
	my_putstr("func set next\n");
}

void set_key_drop(void)
{
	my_putstr("func key drop\n");
}

void set_key_turn(void)
{
	my_putstr("func key turn\n");
}

void set_key_right(void)
{
	my_putstr("func key right\n");
}

void set_key_left(void)
{
	my_putstr("func key left\n");
}

void set_level(void)
{
	my_putstr("func set level\n");
}

void set_help(void)
{
	char *help = my_read("help/help.txt");
	my_putstr(help);
	free(help);
	exit (0);
}

void set_debug(void)
{
	my_putstr("*** DEBUG MODE ***\n");
	my_putstr("Key Left :	");
	my_putstr("\nKey Right :	");
	my_putstr("\nKey Turn :	");
	my_putstr("\nKey Drop :	");
	my_putstr("\nKey Quit :	");
	my_putstr("\nKey Pause :	");
	my_putstr("\nNext :	"); // "Yes" or ("No" ?)
	my_putstr("\nLevel :	");
	my_putstr("\nSize :	");
	my_putstr("\nPress any key to start Tetris");

	my_putstr("\n\nATTENTION LE PRESS KEY MARCHE POUR L'INSTANT QU'AVEC ENTER");
	get_next_line(0);
}
//./tetris -d ‘x’ -D --key-turn=‘ ’ -p ‘p’

int parsing_input(int ac, char **av, keys_t *keys)
{
	for (int i = 0; av[i] != NULL; i++) {
		for (int j = 0; j < 11; j++) {
			if (my_strcmp(av[i], settings[j].long_name) == 0 ||
			my_strcmp(av[i], settings[j].short_name) == 0) {
				//VERIFIER QUE L'AV SUIVENT EST BIEN 'touch' || ='touch' or exit
				//settings[j].callback(av);
				settings[j].callback();
			}
		}
	}
	return (0);
}
