/*
** EPITECH PROJECT, 2017
** Linked list lib
** File description:
** insert an elem in a linked list
*/

#include "mylist.h"

void insert(linked_list_t **list, int index, void *elem)
{
	int len = my_rev_list(list);
	linked_list_t *cur = *list;

	push(&cur, 0);
	for (int i = 0; cur != 0 && i < len - index; i++) {
		cur->data = cur->next->data;
		cur = cur->next;
	}
	cur->data = elem;
	my_rev_list(&cur);
	list = &cur;
}