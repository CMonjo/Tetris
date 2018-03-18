/*
** EPITECH PROJECT, 2017
** strcat
** File description:
** task 2
*/

#include "my.h"
#include <stdlib.h>

char *i_to_a(int number)
{
	char *str;
	int i = 0;

	if (number == 0) {
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	for (int tmp = number; tmp > 0; tmp /= 10, i++);
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i --;
	for (int tp = number; tp > 0; tp /= 10, i--)
		str[i] = tp % 10 + 48;
	return (str);
}
