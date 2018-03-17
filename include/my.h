/*
** EPITECH PROJECT, 2017
** Header file
** File description:
** libmy
*/

#ifndef _MY_H_
	#define _MY_H_
	char *my_revstr(char *str);
	void my_putchar(char c);
	int my_put_nbr(int nb);
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	char *my_strcpy(char *dest, char const *src);
	int my_strcmp(char const *s1, char const *s2);
	int my_strncmp(char const *s1, char const *s2, int nb);
	int my_str_isnum(char const *str);
	char **my_str_to_word_array(char *str, char separator);
	char *my_strcat(char *str1, char *str2);
	int my_getnbr(char const *str);
	char **str_to_array(char *str, char c);
	char *get_next_line(int fd);
	void remove_space(char *str);
	char *replace_tab(char *str);
	void remove_tab(char *str);
#endif
