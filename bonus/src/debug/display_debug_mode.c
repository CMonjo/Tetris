/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Display Debug mode file
*/

#include "main.h"

void display_error(void)
{
	my_putstr("Error input\n");
	exit(84);
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

void display_keys(tetris_t *t)
{
	my_putstr("Key Left : ");
	t->keys->n_left[0] == ' ' && t->keys->n_left[1] == '\0' ?
	my_putstr("(space)") : my_putstr(t->keys->n_left);
	my_putstr("\nKey Right : ");
	t->keys->n_right[0] == ' ' && t->keys->n_right[1] == '\0' ?
	my_putstr("(space)") : my_putstr(t->keys->n_right);
	my_putstr("\nKey Turn : ");
	t->keys->n_turn[0] == ' ' && t->keys->n_turn[1] == '\0' ?
	my_putstr("(space)") : my_putstr(t->keys->n_turn);
	my_putstr("\nKey Drop : ");
	t->keys->n_drop[0] == ' ' && t->keys->n_drop[1] == '\0' ?
	my_putstr("(space)") : my_putstr(t->keys->n_drop);
	my_putstr("\nKey Quit : ");
	t->keys->n_quit[0] == ' ' && t->keys->n_quit[1] == '\0' ?
	my_putstr("(space)") : my_putstr(t->keys->n_quit);
	my_putstr("\nKey Pause : ");
	t->keys->n_pause[0] == ' ' && t->keys->n_pause[1] == '\0' ?
	my_putstr("(space)") : my_putstr(t->keys->n_pause);
}

int set_debug(tetris_t *tetris)
{
	my_putstr("*** DEBUG MODE ***\n");
	display_keys(tetris);
	display_options(tetris);
	open_tetriminos();
	my_putstr("Press any key to start Tetris");
	get_next_line(0);
	return (0);
}
