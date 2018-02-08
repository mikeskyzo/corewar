/*
** EPITECH PROJECT, 2018
** List/Dict lib
** File description:
** Add value to a dict
*/

#include <stdlib.h>
#include "mylist.h"

void dict_add(linked_dict_t **dict, char *label, void *data)
{
	void **var = malloc(2 * sizeof(void *));

	var[0] = label;
	var[1] = data;
	append(dict, var);
}