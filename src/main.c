/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

keys_t *init_keys(void)
{
	keys_t *keys = malloc(sizeof(keys_t));

	keys->left = KEY_LEFT;
	keys->right = KEY_RIGHT;
	keys->turn = KEY_UP;
	keys->drop = KEY_DOWN;
	keys->quit = 'q';
	keys->pause = 'p';
	keys->next = 1;
	keys->level = 1;
	keys->size_x = 10;
	keys->size_y = 20;
	return (keys);
}

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
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < tetris->pieces[i].y; j++)
			free(tetris->pieces[i].piece[j]);
		free(tetris->pieces[i].piece);
	}
	free(tetris->pieces);
	for (int i = 0; i < tetris->y; i++)
		free(tetris->board[i]);
	free(tetris->board);
	free(tetris);
}

int main(int ac, char **av)
{
	layers_t *layers;
	tetris_t *tetris;
	keys_t *keys;
	int return_value = -1;

	srand(time(NULL));
	keys = init_keys();
	if (keys == NULL)
		return (84);
	printf("KEYY (%c)\n", keys->quit);
	return_value = parsing_input(ac, av, keys);
	if (return_value != 0)
		return (return_value);
	layers = fill_layers();
	tetris = create_tetris();
	if (!layers || !tetris)
		return (84);
	display_tetris(layers, tetris, keys);
	free_tetris(layers, tetris);
	return (0);
}
