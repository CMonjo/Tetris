/*
** EPITECH PROJECT, 2017
** Project tetris
** File description:
** display
*/

#include "main.h"

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

void display_info(tetris_t *tetris)
{
	char *str;

	mvprintw(11, 26, tetris->high);
	str = i_to_a(tetris->score);
	mvprintw(12, 26, str);
	str = i_to_a(tetris->lines);
	mvprintw(14, 26, str);
	str = i_to_a(tetris->level);
	mvprintw(15, 26, str);
	tetris->timer = clock() / CLOCKS_PER_SEC;
	str = i_to_a(tetris->timer);
	mvprintw(17, 26, str);
	free(str);
}

void display_layers(layers_t *layers)
{
	attron(COLOR_PAIR(0));
	for (int i = 0; layers->penis[i + 1]; i++)
		mvprintw(19 + i, 24, layers->penis[i]);
	for (int i = 0; layers->name[i + 1]; i++)
		mvprintw(1 + i, 2, layers->name[i]);
	for (int i = 0; layers->board[i + 1]; i++)
		mvprintw(i, 40, layers->board[i]);
	for (int i = 0; layers->score[i + 1]; i++)
		mvprintw(9 + i, 6, layers->score[i]);
	for (int i = 0; layers->text[i + 1]; i++)
		mvprintw(11 + i, 7, layers->text[i]);
	for (int i = 0; layers->next[i + 1]; i++)
		mvprintw(1 + i, 65, layers->next[i]);
	attroff(COLOR_PAIR(0));
}

void display_pieces(tetris_t *t)
{
	for (int i = 0; i < t->pieces[t->next].y; i++) {
		for (int j = 0; j < t->pieces[t->next].x; j++) {
			if (t->pieces[t->next].piece[i][j] != 0) {
				attron(COLOR_PAIR(t->pieces[t->next].color));
				mvprintw(2 + i, 67 + j, "*");
				attroff(COLOR_PAIR(t->pieces[t->next].color));
			}
			else
				mvprintw(2 + i, 67 + j, " ");
		}
	} for (int i = 0; i < t->y; i++) {
		for (int j = 0; j < t->x; j++) {
			if (t->board[i][j] == 0)
				mvprintw(1 + i, 41 + j, " ");
			else {
				attron(COLOR_PAIR(t->board[i][j]));
				mvprintw(1 + i, 41 + j, "*");
				attroff(COLOR_PAIR(t->board[i][j]));
			}
		}
	}
}

void display_tetris(layers_t *layers, tetris_t *tetris)
{
	initscr();
	init_colors();
	curs_set(0);
	keypad(stdscr, TRUE);
	for (int c = 0; c != 'e' && tetris->lose == 0;) {
		clear();
		display_layers(layers);
		display_info(tetris);
		display_pieces(tetris);
		refresh();
		timeout(0.5);
		c = wgetch(stdscr);
		move_tetris(tetris, c);
	}
	endwin();
}
