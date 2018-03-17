/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** return 1 if str contain only digits else 0
*/

int my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i += 1;
	}
	return (1);
}
