/*
** EPITECH PROJECT, =pdate=
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

layers_t *fill_layers(void)
{
	layers_t *layers = malloc(sizeof(layers_t));

	if (!layers)
		return (NULL);
	layers->name = str_to_array(my_read("layers/name.txt"), '\n');
	layers->board = str_to_array(my_read("layers/board.txt"), '\n');
	layers->score = str_to_array(my_read("layers/score.txt"), '\n');
	layers->next = str_to_array(my_read("layers/next.txt"), '\n');
	layers->text = str_to_array(my_read("layers/text.txt"), '\n');
	if (!layers->name || !layers->board || !layers->score|| !layers->next\
	|| !layers->text)
		return (NULL);
	return (layers);
}
