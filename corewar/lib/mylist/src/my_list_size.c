/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** returns the number of elements on the list.
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
	int ans;

	for (ans = 0; begin != 0; ans++)
		begin = begin->next;
	return (ans);
}
