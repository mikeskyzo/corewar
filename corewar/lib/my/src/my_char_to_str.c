/*
** EPITECH PROJECT, 2017
** lib my
** File description:
** my char to str
*/

#include <stdlib.h>

char *my_char_to_str(char c)
{
	char *str = malloc(2);

	str[0] = c;
	str[1] = 0;
	return (str);
}