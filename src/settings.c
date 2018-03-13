/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** settings file
*/

#include "main.h"

settings_t settings[] = {
	{"-h", "--help", 6, &set_help},
	{"-L", "--level=", 8, &set_level},
	{"-l", "--key-left=", 11, &set_key_left},
	{"-r", "--key-right=", 12,  &set_key_right},
	{"-t", "--key-turn=", 11, &set_key_turn},
	{"-d", "--key-drop=", 11, &set_key_drop},
	{"-q", "--key-quit=", 11, &set_key_quit},
	{"-p", "--key-pause=", 12, &set_key_pause},
	{"--map-size", "--map-size", 10, &set_map_size},
	{"-w", "--without-next", 14, &set_next},
	{"-D", "--debug", 7, &set_debug},
	{0, 0, 0, NULL}
};
