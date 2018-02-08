/*
** EPITECH PROJECT, 2017
** CPool_Day11
** File description:
** Applies a function, given as argument, to the data of each node
*/

#include "mylist.h"

linked_list_t *my_find_node(linked_list_t *begin, void const *data_ref,\
int (*cmp)()){
	while (begin != 0) {
		if ((*cmp)(data_ref, begin->data) == 0){
			return (begin);}
		begin = begin->next;
	}
	return (0);
}
