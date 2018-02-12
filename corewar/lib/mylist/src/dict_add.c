/*
** EPITECH PROJECT, 2018
** List/Dict lib
** File description:
** Add value to a dict
*/

#include <stdlib.h>
#include "mylist.h"

static int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (; str[i]; i++);
	return (i);
}

static char *my_strcpy(char *dest, char const *src)
{
	for (int i = 0; i < my_strlen(src); i++)
		dest[i] = src[i];
	dest[my_strlen(src)] = '\0';
	return (dest);
}

static char *my_strdup(char const *src)
{
	return (my_strcpy(malloc(my_strlen(src) * sizeof(char) + 1), src));
}

void dict_add(linked_dict_t **dict, char *label, void *data)
{
	void **var = malloc(2 * sizeof(void *));

	var[0] = my_strdup(label);
	var[1] = data;
	append(dict, var);
}