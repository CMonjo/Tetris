/*
** EPITECH PROJECT, =pdate=
** Project tetris
** File description:
** settings file
*/

#include "main.h"

settings_t settings[] = {
	{"-h", "--help", &set_help},
	{"-L", "--level", &set_level},
	{"-l", "--key-left", &set_key_left},
	{"-r", "--key-right", &set_key_right},
	{"-t", "--key-turn", &set_key_turn},
	{"-d", "--key-drop", &set_key_drop},
	{"-q", "--key-quit", &set_key_quit},
	{"-p", "--key-pause", &set_key_pause},
	{"--map-size", "--map-size", &set_map_size},
	{"-w", "--without-next", &set_next},
	{"-D", "--debug", &set_debug},
	{0, 0, NULL}
};
