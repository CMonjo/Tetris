/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Display Debug mode file
*/

#include "main.h"

void display_keys(keys_t *keys)
{
	(void)keys;
	my_putstr("Key Left : ˆEOD");
	my_putstr("\nKey Right : ˆEOC");
	my_putstr("\nKey Turn : (space)");
	my_putstr("\nKey Drop : x");
	my_putstr("\nKey Quit : q");
	my_putstr("\nKey Pause : p");
}

void display_options(tetris_t *tetris)
{
	my_putstr("\nNext :	");
	if (tetris->display_next == 1)
		my_putstr("Yes");
	else if (tetris->display_next == 0)
		my_putstr("No");
	my_putstr("\nLevel :	");
	my_put_nbr(tetris->level);
	my_putstr("\nSize :	");
	my_put_nbr(tetris->x);
	my_putchar('*');
	my_put_nbr(tetris->y);
}
