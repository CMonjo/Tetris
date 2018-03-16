/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Display Debug mode file
*/

#include "main.h"

int check_extension_file(char *path)
{
	char *tetri = "onimirtet.";
	int check = 0;

	path = my_revstr(path);
	check = my_strncmp(tetri, path, 10);
	path = my_revstr(path);
	return (check);
}

void display_star_tetrimino(int x, char **pieces)
{
	for (int i = 1; i < x + 1; i++) {
		if (my_strlen(pieces[i]) > x + 1)
			return;
		my_putstr(pieces[i]);
		my_putchar('\n');
	}
}

void piece_info(char *piece)
{
	int j = 0;
	char **numbers = str_to_array(piece, ' ');
	char **pieces = str_to_array(piece, '\n');
	int x = my_getnbr(numbers[1]);

	my_putstr(" : Size ");
	for (; piece[j] != ' '; j++)
		my_putchar(piece[j]);
	my_putstr("*");
	for (; piece[j + 1] != ' '; j++)
		my_putchar(piece[j + 1]);
	my_putstr(" : Color ");
	for (; piece[j + 2] != '\n'; j++)
		my_putchar(piece[j + 2]);
	my_putstr(" :\n");
	display_star_tetrimino(x, pieces);
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

	// FIRST LINE
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
	my_putstr("Tetriminos : ");
	my_putstr("Name ");
	for (int i = 0; path[i] != '\0'; i++)
		slash = (path[i] == '/') ? i + 1 : slash;
	for (int i = slash; path[i] != '.' && path[i] != '\0'; i++)
		my_putchar(path[i]);
	if (piece_error(piece) == 84)
		my_putstr(" : Error\n");
	else {
		piece_info(piece);
	}
	free (piece);
	return (0);
}

void swap_path(char **cpy, char *tmp, int i, int nb_path)
{
	for (int j = 0; j < nb_path; j++) {
		if (my_strcmp(cpy[i], cpy[j]) < 0) {
			my_strcpy(tmp, cpy[i]);
			my_strcpy(cpy[i], cpy[j]);
			my_strcpy(cpy[j], tmp);
		}
	}
}

char **tetriminos_alpha(char **path, int nb_path, int len)
{
	char *tmp = malloc(sizeof(char) * (len + 10));
	char **cpy = malloc(sizeof(char *) * (nb_path + 1));

	for (int k = 0; k != nb_path; k++) {
		cpy[k] = malloc(sizeof(char) * (len + 10));
		my_strcpy(cpy[k], path[k]);
		cpy[k + 1] = NULL;
	}
	for (int i = 0; i < nb_path; i++)
		swap_path(cpy, tmp, i, nb_path);
	return (cpy);
}

void loop_tetriminos(char **path, int nb_path)
{
	int len = 0;
	int tmp = 0;
	char **cpy;

	my_putstr("\nTetriminos : ");
	my_put_nbr(nb_path);
	my_putchar('\n');
	for (int k = 0; path[k] != NULL; k++) {
		tmp = my_strlen(path[k]);
		if (tmp > len)
			len = tmp;
	}
	cpy = tetriminos_alpha(path, nb_path, len);
	for (int i = 0; i != nb_path; i++) {
		if (called_tetrimino(cpy[i]) == 84)
			exit(84);
	}
}

void open_tetriminos(void)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	char **path = malloc(sizeof(char *) * 512);
	int nb_path = 0;
	int extension = 0;

	dir = opendir("./tetriminos/");
	if (dir == NULL)
		exit(84);
	while ((file = readdir(dir)) != NULL) {
		extension = check_extension_file(file->d_name);
		if (extension == 0) {
			path[nb_path] = my_strcat("./tetriminos/", file->d_name);
			nb_path++;
		}
	}
	path[nb_path] = NULL;
	closedir(dir);
	loop_tetriminos(path, nb_path);
}
