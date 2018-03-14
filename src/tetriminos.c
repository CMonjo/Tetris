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

piece_t *create_pieces(void)
{
	piece_t *pieces = malloc(sizeof(piece_t) * 6);

	if (!pieces)
		return (NULL);
	pieces[0] = info_piece("pieces/5.tetrimino");
	pieces[1] = info_piece("pieces/6.tetrimino");
	pieces[2] = info_piece("pieces/7.tetrimino");
	pieces[3] = info_piece("pieces/bar.tetrimino");
	pieces[4] = info_piece("pieces/inverted-L.tetrimino");
	pieces[5] = info_piece("pieces/square.tetrimino");
	return (pieces);
}
