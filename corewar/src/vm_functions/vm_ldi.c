/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct ldi for the vm
*/

#include "corewar.h"
#include <stdlib.h>

void load_ind_direct(vm_t *vm, champ_t *champ)
{
	int ind = get_indirect_as_int(vm->ram, (champ->pc + 2) % MEM_SIZE);
	int reg = vm->ram[(champ->pc + 6) % MEM_SIZE];
	int s = get_indirect_as_int(vm->ram, (champ->pc + ind % IDX_MOD) \
% MEM_SIZE);
	byte_t *reg_start = NULL;

	s += get_indirect_as_int(vm->ram, (champ->pc + 4) % MEM_SIZE);
	reg_start = &(champ->registers[(reg - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		reg_start[i] = vm->ram[(champ->pc + (s + i) % IDX_MOD) \
% MEM_SIZE];
	champ->carry = !(champ->carry);
}

void load_two_direct(vm_t *vm, champ_t *champ)
{
	int first = get_indirect_as_int(vm->ram, (champ->pc + 2) % MEM_SIZE);
	int sec = get_indirect_as_int(vm->ram, (champ->pc + 4) % MEM_SIZE);
	int reg = vm->ram[(champ->pc + 6) % MEM_SIZE];
	int s = get_indirect_as_int(vm->ram, champ->pc % MEM_SIZE);
	byte_t *reg_start = NULL;

	s += first + sec;
	reg_start = &(champ->registers[(reg - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		reg_start[i] = vm->ram[(champ->pc + (s + i) % IDX_MOD) \
% MEM_SIZE];
	champ->carry = !(champ->carry);
}

int vm_ldi(vm_t *vm, champ_t *champ)
{
	int type;

	if (vm == NULL || champ == NULL)
		return (-1);
	type = vm->ram[(champ->pc + 1) % MEM_SIZE];
	if (FIRST_PARAM_TYPE(type) == DIRECT_TYPE)
		load_two_direct(vm, champ);
	else
		load_ind_direct(vm, champ);
	return (7);
}
