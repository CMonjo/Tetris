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

layers_t *fill_layers(void)
{
	layers_t *layers = malloc(sizeof(layers_t));

	if (!layers)
		return (NULL);
	layers->name = new_layer("layers/name.txt");
	layers->board = new_layer("layers/board.txt");
	layers->score = new_layer("layers/score.txt");
	layers->next = new_layer("layers/next.txt");
	layers->text = new_layer("layers/text.txt");
	layers->penis = new_layer("layers/penis.txt");
	if (!layers->name || !layers->board || !layers->score|| !layers->next\
	|| !layers->text)
		return (NULL);
	return (layers);
}
