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

	keys->n_left = "ˆEOD";
	keys->n_right = "ˆEOC";
	keys->n_turn = "ˆEOA";
	keys->n_drop = "ˆEOB";
	keys->n_left = "q";
	keys->n_right = "d";
	keys->n_turn = "r";
	keys->n_drop = "s";
	keys->n_quit = "e";
	keys->n_pause = "(space)";
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
	for (int i = 0; layers->art[i]; i++)
		free(layers->art[i]);
	free(layers->art);
	for (int i = 0; layers->loooseeer[i]; i++)
		free(layers->loooseeer[i]);
	free(layers->loooseeer);
	free(layers);
	for (int i = 0; i < tetris->tetriminos; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < tetris->pieces[i][j].y; k++)
				free(tetris->pieces[i][j].piece[k]);
			free(tetris->pieces[i][j].piece);
		}
		free(tetris->pieces[i]);
	}
	free(tetris->pieces);
	for (int i = 0; i < tetris->y; i++)
		free(tetris->board[i]);
	free(tetris->board);
	free(tetris->high);
	free(tetris->keys);
	free(tetris);
}

int main(int ac, char **av)
{
	layers_t *layers;
	tetris_t *tetris;
	int return_value = -1;

	(void)ac;
	srand(time(NULL));
	layers = fill_layers();
	tetris = create_tetris();
	if (tetris->keys == NULL || layers == NULL || tetris == NULL)
		return (84);
	return_value = parsing_input(tetris, tetris->keys, av);
	if (return_value != 0)
		return (return_value);
	tetris->board = create_board(tetris);
	display_tetris(layers, tetris);
	free_tetris(layers, tetris);
	return (0);
}
