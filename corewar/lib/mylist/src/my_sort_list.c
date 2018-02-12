/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Sorts by ascending order
*/

#include <stdlib.h>
#include "mylist.h"

void comp_data(linked_list_t *elem1, linked_list_t *elem2, int (*cmp)())
{
	linked_list_t *swp = malloc(sizeof(linked_list_t));

	if ((*cmp)(elem1->data, elem2->data) > 0) {
		swp->data = elem2->data;
		elem2->data = elem1->data;
		elem1->data = swp->data;
	}
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
	linked_list_t *cur = *begin;

	for (int i = 0; i <= my_list_size(cur); i++) {
		while ((*begin)->next != 0) {
			comp_data((*begin), (*begin)->next, (cmp));
			(*begin) = (*begin)->next;
		}
		(*begin) = cur;
	}
}
