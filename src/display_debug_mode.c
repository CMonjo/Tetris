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
	my_putstr("Key Left : ");
	my_putstr(keys->n_left);
	my_putstr("\nKey Right : ");
	my_putstr(keys->n_right);
	my_putstr("\nKey Turn : ");
	my_putstr(keys->n_turn);
	my_putstr("\nKey Drop : ");
	my_putstr(keys->n_drop);
	my_putstr("\nKey Quit : ");
	my_putstr(keys->n_quit);
	my_putstr("\nKey Pause : ");
	my_putstr(keys->n_pause);
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
