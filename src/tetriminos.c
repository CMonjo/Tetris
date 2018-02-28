/*
** EPITECH PROJECT, =pdate=
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
	piece.piece = malloc(sizeof(char *) * (piece.y + 1));
	for (int j = 1, k = 0, m = 0; lines[j]; j++, k = 0, m = 0) {
		piece.piece[j - 1] = malloc(sizeof(char) * (piece.x + 1) * 2);
		for (; lines[j][k] != '\0'; k++, m++) {
			piece.piece[j - 1][m] = lines[j][k];
			(lines[j][k + 1] != '\0') ?\
			piece.piece[j - 1][m + 1] = ' ' : 0;
			(lines[j][k + 1] != '\0') ? m++ : 0;
		}
		piece.piece[j - 1][m] = '\0';
	}
	piece.piece[piece.y] = NULL;
	free(file);
	return (piece);
}

piece_t *create_pieces(void)
{
	piece_t *pieces;

	pieces = malloc(sizeof(piece_t) * 1);
	pieces[0] = info_piece("pieces/6.tetrimino");
	return (pieces);
}
