/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void free_tetris(layers_t *layers, tetris_t *tetris)
{
	for (int i = 0; layers->name[i]; i++)
		free(layers->name[i]);
	free(layers->name);
	for (int i = 0; layers->board[i]; i++)
		free(layers->board[i]);
	free(layers->board);
	for (int i = 0; layers->score[i]; i++)
		free(layers->score[i]);
	free(layers->score);
	for (int i = 0; layers->next[i]; i++)
		free(layers->next[i]);
	free(layers->next);
	for (int i = 0; layers->text[i]; i++)
		free(layers->text[i]);
	free(layers->text);
	free(layers);
	// for (int i = 0; i < 6; i++) {
	// 	for (int j = 0; tetris->pieces[i].piece[j]; j++)
	// 		free(tetris->pieces[i].piece[j]);
	// 	free(tetris->pieces[i].piece);
	// }
	free(tetris->pieces);
	free(tetris);
}

int tetris_help(int ac, char **av)
{
	char *help;

	if (ac == 2 && (my_strcmp(av[1], "-help") == 0 ||
	my_strcmp(av[1], "--help") == 0)) {
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
	tetris_t *tetris;

	srand(time(NULL));
	if (tetris_help(ac, av) == 1)
		return (0);
	layers = fill_layers();
	tetris = create_tetris();
	if (!layers || !tetris)
		return (84);
	display_tetris(layers, tetris);
	//free_tetris(layers, tetris);
	return (0);
}
