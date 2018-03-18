/*
** EPITECH PROJECT, 2017
** strcat
** File description:
** task 2
*/

#include "my.h"
#include <stdlib.h>

char *concat_path(char *str1, char *str2)
{
	int len = my_strlen(str1) + my_strlen(str2) + 1;
	char *dest = malloc(sizeof(char) * len);
	int i = 0;
	int j = 0;

	if (!dest)
		return (NULL);
	while (str1[i] != '\0') {
		dest[i] = str1[i];
		i ++;
	}
	while (str2[j] != '\0') {
		dest[i] = str2[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}
