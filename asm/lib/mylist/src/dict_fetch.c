/*
** EPITECH PROJECT, 2018
** List/Dict lib
** File description:
** Fetch value to a dict
*/

#include "mylist.h"

static int my_strlen(char const *str)
{
	int len = 0;

	for (; str[len]; len++);
	return (len);
}

static int my_strcmp(char const *s1, char const *s2)
{
	int ind = 0;

	for (; s1[ind] != 0 && s2[ind] != 0; ind++)
		if (s1[ind] < s2[ind])
			return (s1[ind] - s2[ind]);
		else if (s1[ind] > s2[ind])
			return (s1[ind] - s2[ind]);
	if (my_strlen(s1) > my_strlen(s2))
		return (s1[ind]);
	else if (my_strlen(s2) > my_strlen(s1))
		return (- s2[ind]);
	return (0);
}

void *dict_fetch(linked_dict_t *dict, char *label)
{
	linked_dict_t *cur = dict;

	for (; cur != 0; cur = cur->next) {
		if (!my_strcmp(((void **)(cur->data))[0], label))
			return (((void **)(cur->data))[1]);
	}
	return ((void *)- 1);
}