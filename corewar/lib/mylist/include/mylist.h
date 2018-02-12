/*
** EPITECH PROJECT, 2017
** List lib
** File description:
** Lib header
*/

#ifndef __BTA_LIST_H_
#define __BTA_LIST_H_

typedef struct node {
	void *data;
	struct node *next;
} linked_list_t;

typedef linked_list_t linked_dict_t;

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *));
void my_concat_list(linked_list_t **list1, linked_list_t *list2);
int my_delete_nodes(linked_list_t **list, void const *data_ref, int (*cmp)());
int my_list_size(linked_list_t const *list);
int my_rev_list(linked_list_t const **list);
void my_sort_list(linked_list_t **list, int (*cmp)());
void push(linked_list_t **list, void *elem);
void append(linked_list_t **list, void *elem);
void *pop(linked_list_t **list);
void dict_add(linked_dict_t **dict, char *label, void *data);
void *dict_fetch(linked_dict_t *dict, char *label);
void dict_destroy(linked_dict_t *dict);

#endif