/*
** EPITECH PROJECT, 2017
** Header file
** File description:
** Library tools
*/

#ifndef _TOOLS_H_
	#define _TOOLS_H_
	void my_putchar(char c);
	int my_put_nbr(int nb);
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	int my_getnbr(char const *str);
	char **str_to_array(char *str, char c);
	char *get_next_line(int fd);
	void remove_space(char *str);
	char *replace_tab(char *str);
	void remove_tab(char *str);
#endif
