/*
** EPITECH PROJECT, 2017
** Project Tetris
** File description:
** Main file
*/

#include "tools.h"

void remove_space(char *str)
{
	char *i = str;
	char *j = str;

	while (*j != '\0') {
		*i = *j++;
		if (*i != '\t')
			i++;
	}
	*i = '\0';
}
