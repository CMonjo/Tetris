/*
** EPITECH PROJECT, 2017
** Project Tetris
** File description:
** Main file
*/

#include "tools.h"

void remove_tab(char *str)
{
	char *i = str;
	char *j = str;

	while (*j != '\0') {
		*i = *j++;
		if (*i != ' ')
			i++;
	}
	*i = '\0';
}

char *replace_tab(char *str)
{
	for (int j = 0; str[j] != '\0'; j++)
		if (str[j] == '\t')
			str[j] = ' ';
	return (str);
}
