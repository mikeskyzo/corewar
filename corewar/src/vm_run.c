/*
** EPITECH PROJECT, 2018
** Corewar 2017
** File description:
** execution loop
*/

#include "mylist.h"
#include "corewar.h"
#include <stdlib.h>

static void copy_champ_tab(vm_t *vm)
{
	for (int i = 0; i < vm->nb_champ; i++)
		append(&(vm->programs), &(vm->champ_tab[i]));
}

void do_funct(vm_t *vm, champ_t *champ, int ins)
{
	if (ins != champ->next_ins) {
		champ->next_ins = ins;
		champ->nb_next_ins = op_tab[ins - 1].nbr_cycles;
	}
	else if (champ->nb_next_ins <= 0) {
		champ->pc += op_tab[ins - 1].funct_vm(vm, champ);
	}
	else
		champ->nb_next_ins--;

}

static void execute_cycle(vm_t *vm, champ_t *champ)
{
	int ins = vm->ram[champ->pc % MEM_SIZE];

	champ->nb_cycle_live++;
	if (champ->nb_cycle_live > CYCLE_TO_DIE) {
		champ->alive = false;
		return;
	}
	if (ins == 0 || ins > 16) {
		champ->pc++;
		return;
	}
	do_funct(vm, champ, ins);
}

int vm_run(vm_t *vm)
{
	copy_champ_tab(vm);
	while (1 < nb_prog_alive(vm)) {
		for (linked_list_t *cur = vm->programs; cur; cur = cur->next)
			execute_cycle(vm, cur->data);
		vm->current_cycle++;
		if (vm->dump == vm->current_cycle) {
			display_coredump(vm);
			return (0);
		}
	}
	find_win(vm);
	free(vm);
	return (0);
}
