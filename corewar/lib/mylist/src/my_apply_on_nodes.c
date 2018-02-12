/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Applies a function, given as argument, to the data of each node
*/

#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
	while (begin != 0) {
		(*f)(begin->data);
		begin = begin->next;
	}
	return (0);
}
