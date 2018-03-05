/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** find the winner and display
*/

#include "corewar.h"
#include "my.h"
#include "mylist.h"

int is_alive(champ_t *champ)
{
	if (champ->alive == true)
		return (1);
	return (0);
}

void print_win(champ_t *champ)
{
	my_printf(WON_STR, champ->nb_prog, champ->header.prog_name);
}

void find_win(vm_t *vm)
{
	linked_list_t *cur = vm->programs;
	int i = 1;

	for (; cur != NULL; i++, cur = cur->next)
		if (is_alive(cur->data) == 1)
			break;
	if (i >= my_list_size(vm->programs))
		my_printf("Equality, no winner\n");
	else
		print_win(cur->data);
}
