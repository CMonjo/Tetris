/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** tetriminos
*/

#include "main.h"

piece_t info_piece(char *path)
{
	piece_t piece;
	char *file = my_read(path);
	char **lines = str_to_array(file, '\n');
	char **info = str_to_array(lines[0], ' ');

	piece.x = my_getnbr(info[0]);
	piece.y = my_getnbr(info[1]);
	piece.color = my_getnbr(info[2]);
	piece.piece = malloc(sizeof(int *) * piece.y);
	for (int j = 1; j < piece.y + 1; j++) {
		piece.piece[j - 1] = malloc(sizeof(int) * piece.x);
		for (int i = 0; i < piece.x; i++) {
			piece.piece[j - 1][i] = (lines[j][i] == '*')
			? piece.color : 0;
		}
	}
	free(file);
	for (int i = 0; lines[i]; i++)
		free(lines[i]);
	free(lines);
	for (int i = 0; info[i]; i++)
		free(info[i]);
	free(info);
	return (piece);
}

void create_rotate(piece_t *pieces)
{
	pieces[1].piece = malloc(sizeof(int *) * pieces[1].y);
	pieces[2].piece = malloc(sizeof(int *) * pieces[2].y);
	pieces[3].piece = malloc(sizeof(int *) * pieces[3].y);
	for (int i = 0; i < pieces[1].y; i++) {
		pieces[1].piece[i] = malloc(sizeof(int) * pieces[1].x);
		for (int j = 0; j < pieces[1].x; j++)
			pieces[1].piece[i][j] =
			pieces[0].piece[pieces[0].y - 1 - j][i];
	} for (int i = 0; i < pieces[2].y; i++) {
		pieces[2].piece[i] = malloc(sizeof(int) * pieces[2].x);
		for (int j = 0; j < pieces[2].x; j++)
			pieces[2].piece[i][j] =
			pieces[1].piece[pieces[1].y - 1 - j][i];
	} for (int i = 0; i < pieces[3].y; i++) {
		pieces[3].piece[i] = malloc(sizeof(int) * pieces[3].x);
		for (int j = 0; j < pieces[3].x; j++)
			pieces[3].piece[i][j] =
			pieces[2].piece[pieces[2].y - 1 - j][i];
	}
}

piece_t *create_rotation(char *path)
{
	piece_t *pieces = malloc(sizeof(piece_t) * 4);

	pieces[0] = info_piece(path);
	for (int i = 1; i < 4; i++) {
		pieces[i].color = pieces[0].color;
		if (i == 2) {
			pieces[i].x = pieces[0].x;
			pieces[i].y = pieces[0].y;
		} else {
			pieces[i].x = pieces[0].y;
			pieces[i].y = pieces[0].x;
		}
	}
	create_rotate(pieces);
	return (pieces);
}

piece_t **create_pieces(void)
{
	piece_t **pieces = malloc(sizeof(piece_t *) * 6);

	if (!pieces)
		return (NULL);
	pieces[0] = create_rotation("pieces/5.tetrimino");
	pieces[1] = create_rotation("pieces/6.tetrimino");
	pieces[2] = create_rotation("pieces/7.tetrimino");
	pieces[3] = create_rotation("pieces/bar.tetrimino");
	pieces[4] = create_rotation("pieces/inverted-L.tetrimino");
	pieces[5] = create_rotation("pieces/square.tetrimino");
	return (pieces);
}
