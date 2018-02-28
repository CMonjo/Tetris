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

int main(int ac, char **av)
{
	layers_t *layers;
	piece_t *pieces;

	if (ac != 1)
		return (84);
	layers = fill_layers();
	pieces = create_pieces();
	if (!layers || !pieces)
		return (84);
	av = av;
	display_tetris(layers, pieces);
	free_tetris(layers, pieces);
	return (0);
}
