/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void free_layers(layers_t *layers)
{
	for (int i = 0; layers->name[i]; i++)
	free(layers->name[i]);
	free(layers->name);
	free(layers->board);
	for (int i = 0; layers->score[i]; i++)
	free(layers->score[i]);
	free(layers->score);
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
}

void free_pieces(tetris_t *tetris, int i, int j)
{
	for (int k = 0; k < tetris->pieces[i][j].y; k++)
		free(tetris->pieces[i][j].piece[k]);
}

void free_tetris(tetris_t *tetris)
{
	for (int i = 0; i < tetris->tetriminos; i++) {
		for (int j = 0; j < 4; j++) {
			free_pieces(tetris, i, j);
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
