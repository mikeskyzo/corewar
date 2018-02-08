/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Reverses a linked list
*/

#include "mylist.h"

int my_rev_list(linked_list_t const **begin)
{
	linked_list_t const *cpy = *begin;
	linked_list_t *ans = 0;
	int i = 0;

	for (; cpy != 0; i++) {
		push(&ans, cpy->data);
		cpy = cpy->next;
	}
	*begin = ans;
	return (i);
}
