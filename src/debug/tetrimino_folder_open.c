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
	struct dirent *file = NULL;
	char **path = malloc(sizeof(char *) * 512);
	int nb_path = 0;
	int extension = 0;
	DIR *dir = NULL;

	dir = opendir("./tetriminos/");
	if (dir == NULL)
		exit(84);
	while ((file = readdir(dir)) != NULL) {
		extension = check_extension_file(file->d_name);
		if (extension == 0) {
			path[nb_path] =
			my_strcat("./tetriminos/", file->d_name);
			nb_path++;
		}
	}
	path[nb_path] = NULL;
	closedir(dir);
	loop_tetriminos(path, nb_path);
}
