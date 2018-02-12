/*
** EPITECH PROJECT, 2017
** My lib
** File description:
** Push an element into a linked list
*/

#include <stdlib.h>
#include "mylist.h"

void push(linked_list_t **list, void *elem)
{
	linked_list_t *new_elem;

	new_elem = malloc(sizeof(linked_list_t));
	new_elem->data = elem;
	new_elem->next = *list;
	*list = new_elem;
}
