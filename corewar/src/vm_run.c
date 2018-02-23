/*
** EPITECH PROJECT, 2018
** Corewar 2017
** File description:
** execution loop
*/

#include "mylist.h"
#include "corewar.h"

static void copy_champ_tab(vm_t *vm)
{
	for (int i = 0; i < vm->nb_champ; i++)
		append(&(vm->programs), &(vm->champ_tab[i]));
}

static void execute_cycle(vm_t *vm, champ_t *champ)
{
	int ins_nb = -1;

	champ->nb_next_ins++;
	if (0 < champ->nb_next_ins)
		return;
	for (ins_nb = 0; op_tab[ins_nb].mnemonique; ins_nb++);
	if (0 < *(champ->pc) && *(champ->pc) < ins_nb)
		(void)champ->pc;
	else
		champ->pc = (byte_t *)((long)(champ->pc + 1) % MEM_SIZE);
}

int vm_run(vm_t *vm)
{
	copy_champ_tab(vm);
	while (1 < my_list_size(vm->programs)) {
		for (linked_list_t *cur = vm->programs; cur; cur = cur->next)
			execute_cycle(vm, cur->data);
		vm->current_cycle++;
		if (vm->dump < vm->current_cycle) {
			display_coredump(vm);
			return (0);
		}
	}
	find_win(vm);
	return (0);
}