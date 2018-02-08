/*
** EPITECH PROJECT, 2018
** List/Dict lib
** File description:
** Fetch value to a dict
*/

#include <stdlib.h>
#include "mylist.h"

void dict_destroy(linked_dict_t *dict)
{
	linked_dict_t *cur = dict;

	while (dict) {
		cur = dict;
		dict = dict->next;
		free(cur->data);
		free(cur);
	}
}