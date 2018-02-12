/*
** EPITECH PROJECT, 2017
** Corewar asm
** File description:
** get operator with name
*/

#include "my.h"
#include "op.h"

op_t get_op(char *mnemonique)
{
	int i = 0;

	for (i = 0; op_tab[i].mnemonique != NULL; i++) {
		if (my_strcmp(mnemonique, op_tab[i].mnemonique) == 0) {
			return (op_tab[i]);
		}
	}
	return (op_tab[i]);
}

int get_op_index(op_t op)
{
	for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
		if (my_strcmp(op.mnemonique, op_tab[i].mnemonique) == 0) {
			return (i);
		}
	}
	return (-1);
}