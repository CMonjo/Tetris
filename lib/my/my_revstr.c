/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** Reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
	int i = 0;
	int a = 0;
	char str2[1000];

	while (str[i] != '\0') {
		str2[i] = str[i];
		i++;
	}
	i--;
	while (i >= 0) {
		str[a] = str2[i];
		i--;
		a++;
	}
	return (str);
}
