/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void free_tetris(layers_t *layers, piece_t *pieces)
{
	free(layers->name);
	free(layers->board);
	free(layers->score);
	free(layers->next);
	free(layers->text);
	free(layers);
	free(pieces);
}

int tetris_help(int ac, char **av)
{
	char *help;

	if (ac == 2 && my_strcmp(av[1], "-help")) {
		help = my_read("text/help.txt");
		my_putstr(help);
		free(help);
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	layers_t *layers;
	piece_t *pieces;

	if (tetris_help(ac, av) == 1)
		return (0);
	layers = fill_layers();
	pieces = create_pieces();
	if (!layers || !pieces)
		return (84);
	display_tetris(layers, pieces);
	free_tetris(layers, pieces);
	return (0);
}
