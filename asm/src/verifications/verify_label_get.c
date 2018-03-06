/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** verify unknown label get
*/

/* File created the 06/03/2018 at 21:53:39 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int are_label_get_valid(assembly_data_t *data)
{
	linked_list_t *curr = NULL;
	linked_list_t *last = NULL;
	label_get_t *label = NULL;
	int to_return = 1;

	for (curr = data->label_gets; curr; curr = curr->next) {
		if (last != NULL) {
			free(((label_get_t *)last->data)->name);
			free(last->data);
			free(last);
		}
		label = curr->data;
		if (dict_fetch(data->labels, &label->name[1]) == ((void *)-1)) {
			to_return = 0;
			my_strcpy(data->error_msg, ERR_UNKNOWN_LABEL);
			data->error_line = label->line;
			write_error_message(data);
		}
		last = curr;
	}
	return (to_return);
}