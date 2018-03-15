/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

char *i_to_a(int number)
{
	char *str;
	int i = 0;

	if (number == 0) {
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	for (int tmp = number; tmp > 0; tmp /= 10, i++);
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i --;
	for (int tp = number; tp > 0; tp /= 10, i--)
		str[i] = tp % 10 + 48;
	return (str);
}

keys_t *init_keys(void)
{
	keys_t *keys = malloc(sizeof(keys_t));

	keys->left = KEY_LEFT;
	keys->right = KEY_RIGHT;
	keys->turn = KEY_UP;
	keys->drop = KEY_DOWN;
	keys->quit = 'q';
	keys->pause = 'p';
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

	(void)ac;
	srand(time(NULL));
	keys = init_keys();
	layers = fill_layers();
	tetris = create_tetris();
	if (keys == NULL || layers == NULL || tetris == NULL)
		return (84);
	return_value = parsing_input(tetris, keys, av);
	if (return_value != 0)
		return (return_value);
	if (!layers || !tetris)
		return (84);
	display_tetris(layers, tetris);
	free_tetris(layers, tetris);
	return (0);
}
