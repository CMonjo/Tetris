/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Main file
*/

#include "main.h"

char *my_read(char *path)
{
	char *map = malloc(sizeof(char));
	char *buffer = malloc(sizeof(char) * 4096);
	int fd = open(path, O_RDONLY);
	int rd;

	if (!map || !buffer || fd < 0)
		return (NULL);
	rd = read(fd, buffer, 4094);
	map[0] = '\0';
	while (rd > 0) {
		buffer[rd] = '\0';
		map = my_strcat(map, buffer);
		if (!map)
			return (NULL);
		rd = read(fd, buffer, 4094);
	}
	close(fd);
	free(buffer);
	return (map);
}

void display_map(layers_t *layers)
{
	int c;

	initscr();
	curs_set(0);
	keypad(stdscr, TRUE);
	while (c != 'e') {
		clear();
		mvprintw(0, 0, layers->name);
		refresh();
		c = wgetch(stdscr);
	}
	endwin();
}

layers_t *fill_layers(void)
{
	layers_t *layers = malloc(sizeof(layers_t));

	if (!layers)
		return (NULL);
	layers->name = my_read("layers/name.txt");
	layers->board = my_read("layers/board.txt");
	if (!layers->name || !layers->board)
		return (NULL);
	return (layers);
}

void free_layers(layers_t *layers)
{
	free(layers->name);
	free(layers->board);
	free(layers);
}

int main(int ac, char **av)
{
	layers_t *layers;

	if (ac != 1)
		return (84);
	layers = fill_layers();
	if (!layers)
		return (84);
	av = av;
	display_map(layers);
	free_layers(layers);
	return (0);
}
