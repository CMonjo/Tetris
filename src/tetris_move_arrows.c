/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** Main file
*/

#include "main.h"

void tetris_up_down(tetris_t *t, int *x, int *y, int c)
{
	if (c == 258) {
		(my_strlen(t->keys->n_turn) == 5 && t->keys->n_turn[4] == 'B')
		? t->rot++ : 0;
		(my_strlen(t->keys->n_drop) == 5 && t->keys->n_drop[4] == 'B')
		? (*y)++ : 0;
		(my_strlen(t->keys->n_right) == 5 && t->keys->n_right[4] == 'B')
		? (*x)++ : 0;
		(my_strlen(t->keys->n_left) == 5 && t->keys->n_left[4] == 'B')
		? (*x)-- : 0;
	} else if (c == 259) {
		(my_strlen(t->keys->n_turn) == 5 && t->keys->n_turn[4] == 'A')
		? t->rot++ : 0;
		(my_strlen(t->keys->n_drop) == 5 && t->keys->n_drop[4] == 'A')
		? (*y)++ : 0;
		(my_strlen(t->keys->n_right) == 5 && t->keys->n_right[4] == 'A')
		? (*x)++ : 0;
		(my_strlen(t->keys->n_left) == 5 && t->keys->n_left[4] == 'A')
		? (*x)-- : 0;
	}
}

void tetris_right_left(tetris_t *t, int *x, int *y, int c)
{
	if (c == 260) {
		(my_strlen(t->keys->n_turn) == 5 && t->keys->n_turn[4] == 'D')
		? t->rot++ : 0;
		(my_strlen(t->keys->n_drop) == 5 && t->keys->n_drop[4] == 'D')
		? (*y)++ : 0;
		(my_strlen(t->keys->n_right) == 5 && t->keys->n_right[4] == 'D')
		? (*x)++ : 0;
		(my_strlen(t->keys->n_left) == 5 && t->keys->n_left[4] == 'D')
		? (*x)-- : 0;
	} else if (c == 261) {
		(my_strlen(t->keys->n_turn) == 5 && t->keys->n_turn[4] == 'C')
		? t->rot++ : 0;
		(my_strlen(t->keys->n_drop) == 5 && t->keys->n_drop[4] == 'C')
		? (*y)++ : 0;
		(my_strlen(t->keys->n_right) == 5 && t->keys->n_right[4] == 'C')
		? (*x)++ : 0;
		(my_strlen(t->keys->n_left) == 5 && t->keys->n_left[4] == 'C')
		? (*x)-- : 0;
	}
}
