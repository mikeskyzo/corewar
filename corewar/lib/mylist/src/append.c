/*
** EPITECH PROJECT, 2017
** List lib
** File description:
** Append to the list
*/

#include <stdlib.h>
#include "mylist.h"

void append(linked_list_t **list, void *item)
{
	linked_list_t *cur = *list;
	linked_list_t *new = malloc(sizeof(*new));

	new->data = item;
	new->next = 0;
	if (*list == 0) {
		*list = new;
		return;
	}
	for (int i = 0; i < my_list_size(*list) - 1; i++)
		cur = (cur != 0) ? cur->next : 0;
	cur->next = new;
}