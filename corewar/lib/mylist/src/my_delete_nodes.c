/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Deletes a given node
*/

#include <stdlib.h>
#include "mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
	linked_list_t *ans = *begin;

	while ((*cmp)((*begin)->data, data_ref) == 0) {
		ans = (*begin)->next;
		free(*begin);
		*begin = ans;
	}
	while ((*begin)->next != 0) {
		if ((*cmp)(((*begin)->next)->data, data_ref) != 0) {
			(*begin) = (*begin)->next;
		} else
			(*begin)->next = ((*begin)->next)->next;
	}
	*begin = ans;
	return (0);
}
