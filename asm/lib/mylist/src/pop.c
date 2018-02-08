/*
** EPITECH PROJECT, 2017
** My lib
** File description:
** Push an element into a linked list
*/

#include <stdlib.h>
#include "mylist.h"

void *pop(linked_list_t **list)
{
	void *ret_elem;
	linked_list_t *to_free;

	ret_elem = (*list)->data;
	to_free = (*list);
	if ((*list)->next != 0) {
		(*list) = (*list)->next;
		free(to_free);
	} else {
		(*list)->data = 0;
	}
	return (ret_elem);
}
