/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** return the index if the str contains the value, -1 otherwise
*/

#include "my.h"

int my_str_contains(char c, char const *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			return (i);
	}
	return (-1);
}