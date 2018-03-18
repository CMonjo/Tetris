/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

keys_t *init_keys(void)
{
	keys_t *keys = malloc(sizeof(keys_t));

	keys->n_left = "ˆEOD";
	keys->n_right = "ˆEOC";
	keys->n_turn = "ˆEOA";
	keys->n_drop = "ˆEOB";
	keys->n_quit = "q";
	keys->n_pause = "(space)";
	keys->debug = 0;
	keys->error_input = 0;
	keys->my_break = 0;
	return (keys);
}

void stock_score(tetris_t *tetris)
{
	int fd;
	char *score;

	if (tetris->score > my_getnbr(tetris->high)) {
		fd = open("help/high_score.txt", O_WRONLY);
		score = i_to_a(tetris->score);
		write(fd, score, my_strlen(score));
		close(fd);
		free(score);
	}
}

int main(int ac, char **av)
{
	layers_t *layers;
	tetris_t *tetris;
	int return_value = -1;

	(void)ac;
	layers = fill_layers();
	tetris = create_tetris();
	if (tetris->keys == NULL || layers == NULL || tetris == NULL)
		return (84);
	return_value = parsing_input(tetris, av);
	if (return_value != 0)
		return (return_value);
	tetris->board = create_board(tetris);
	game_loop(layers, tetris);
	stock_score(tetris);
	free_layers(layers);
	free_tetris(tetris);
	return (0);
}
