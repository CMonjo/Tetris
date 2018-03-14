/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Display Debug mode file
*/

#include "main.h"

void piece_info(char *piece)
{
	int j = 0;
	char **numbers = str_to_array(piece, ' ');
	char **pieces = str_to_array(piece, '\n');
	int x = my_getnbr(numbers[1]);

	printf(" : Size ");
	for (; piece[j] != ' '; j++)
		printf("%c", piece[j]);
	printf("*");
	for (; piece[j + 1] != ' '; j++)
		printf("%c", piece[j + 1]);
	printf(" : Color ");
	for (; piece[j + 2] != '\n'; j++)
		printf("%c", piece[j + 2]);
	printf(" :\n");
	for (int i = 1; i < x + 1; i++) {
		if (my_strlen(pieces[i]) > x)
			return;
		printf("%s\n", pieces[i]);
	}
}

int form_error(char *piece)
{
	char **len = str_to_array(piece, '\n');
	char **numbers = str_to_array(piece, ' ');
	int y = 0;
	int x = 0;
	int lines = 0;

	if (!len)
		return (84);
	x = my_getnbr(numbers[0]);
	y = my_getnbr(numbers[1]);
	for (int i = 0; piece[i] != '\0'; i++)
		lines += (piece[i] == '\n') ? 1 : 0;
	if (y > lines - 1 || my_strlen(len[1]) > x)
		return (84);
	return (0);
}

int piece_error(char *piece)
{
	int i = 0;
	int space = 0;

	for (int j = 0; piece[j] != '\n'; j++)
		if ((piece[j] < '0' || piece[j] > '9') && piece[j] != ' ')
			return (84);
	for (; piece[i] == ' '; i++);
	if (i > 0 || form_error(piece) == 84)
		return (84);
	for (; piece[i] != '\n'; i++)
		space += (piece[i] == ' ') ? 1 : 0;
	if (space != 2)
		return (84);
	return (0);
}

int called_tetrimino(char *path)
{
	char *piece = my_read(path);
	int slash = 0;
	if (piece == NULL)
		return (84);
	printf("Tetriminos : ");
	printf("Name ");
	for (int i = 0; path[i] != '\0'; i++)
		slash = (path[i] == '/') ? i + 1 : slash;
	for (int i = slash; path[i] != '.' && path[i] != '\0'; i++)
		printf("%c", path[i]);
	if (piece_error(piece) == 84)
		printf(" | Error\n");
	else
		piece_info(piece);
	free (piece);
	return (0);
}

int open_tetriminos(void)
{
	my_putchar('\n');
	my_putstr("Tetriminos : <size>\n");
	DIR *dir = NULL;
	struct dirent *file = NULL;
	char *path;

	dir = opendir("./pieces/");
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.') {
			path = my_strcat("./pieces/", file->d_name);
			if (called_tetrimino(path) == 84)
				return (84);
			free(path);
		}
	}
	closedir(dir);
	return (0);
}
