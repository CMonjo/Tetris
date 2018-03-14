/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** Concat str
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

char **my_str_to_word_array(char *str, char c)
{
	int i = 1;
	int mal = 0;
	char **dest;

	for (int j = 0; str[j] != '\0'; j++)
		i = str[j] == c ? i + 1 : i;
	dest = malloc(sizeof(char *) * (i + 1));
	for (int j = 0, k = 0; j < i; j ++, k ++, mal = 0) {
		for (; str[k] != c && str[k] != '\0'; k ++, mal ++);
		dest[j] = malloc(sizeof(char) * (mal + 1));
	}
	for (int m = 0, k = 0, j = 0; k < i; k ++, j++, m = 0) {
		for (; str[j] != c && str[j] != '\0'; m++, j++)
			dest[k][m] = str[j];
		dest[k][m] = '\0';
	}
	dest[i] = NULL;
	return (dest);
}
