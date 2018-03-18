/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** create layers
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

char **new_layer(char *path)
{
	char *str = my_read(path);
	char **array;

	if (!str)
		return (NULL);
	array = str_to_array(str, '\n');
	free(str);
	if (!array)
		return (NULL);
	return (array);
}

char *new_board(char *path)
{
	char *str = my_read(path);
	char *board = malloc(sizeof(char) * 7);

	for (int i = 0; i < 5; i++)
		board[i] = str[i + 2];
	board[4] = str[0];
	board[5] = str[1];
	board[6] = '\0';
	free(str);
	return (board);
}

layers_t *fill_layers(void)
{
	layers_t *layers = malloc(sizeof(layers_t));

	if (!layers)
		return (NULL);
	layers->name = new_layer("layers/name.txt");
	layers->board = new_board("layers/board.txt");
	layers->score = new_layer("layers/score.txt");
	layers->next = new_board("layers/next.txt");
	layers->text = new_layer("layers/text.txt");
	layers->art = new_layer("layers/art.txt");
	layers->loooseeer = new_layer("layers/loooseeer.txt");
	if (!layers->name || !layers->board || !layers->score|| !layers->next
	|| !layers->text || !layers->art || !layers->loooseeer)
		return (NULL);
	return (layers);
}
