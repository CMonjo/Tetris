/*
** EPITECH PROJECT, 2018
** exec
** File description:
** str_to_word
*/

#include <stdlib.h>
#include <stdio.h>

char **str_to_array(char *str, char c)
{
	int i = 1;
	int mal = 0;
	char **dest;

	for (int j = 0; str[j] != '\0'; i = str[j] == c ? i + 1 : i, j++);
	dest = malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	for (int j = 0, k = 0; j < i; j ++, k ++, mal = 0) {
		for (; str[k] != c && str[k] != '\0'; k ++, mal ++);
		dest[j] = malloc(sizeof(char) * (mal + 1));
		if (!dest[j])
			return (NULL);
	} for (int m = 0, k = 0, j = 0; k < i; k ++, j++, m = 0) {
		for (; str[j] != c && str[j] != '\0'; m++, j++)
			dest[k][m] = str[j];
		dest[k][m] = '\0';
	}
	dest[i] = NULL;
	return (dest);
}
