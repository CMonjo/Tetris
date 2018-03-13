/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** Display Debug mode file
*/

#include "main.h"

void display_keys(keys_t *keys)
{
	my_putstr("Key Left :	");
	my_putchar(keys->left);
	my_putstr("\nKey Right :	");
	my_putchar(keys->right);
	my_putstr("\nKey Turn :	");
	my_putchar(keys->turn);
	my_putstr("\nKey Drop :	");
	my_putchar(keys->drop);
	my_putstr("\nKey Quit :	");
	my_putchar(keys->quit);
	my_putstr("\nKey Pause :	");
	my_putchar(keys->pause);

}

void display_options(tetris_t *tetris)
{
	my_putstr("\nNext :	");
	if (tetris->next == 1)
		my_putstr("Yes");
	else if (tetris->next == 0)
		my_putstr("No");
	my_putstr("\nLevel :	");
	my_put_nbr(tetris->level);
	my_putstr("\nSize :	");
	my_put_nbr(tetris->y);
	my_putchar('*');
	my_put_nbr(tetris->x);
}
