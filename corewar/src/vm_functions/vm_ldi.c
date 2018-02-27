/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct ldi for the vm
*/

#include "corewar.h"
#include <stdlib.h>

int vm_ldi(vm_t *vm, byte_t *instruction, champ_t *champ)
{
	int ind = get_indirect_as_int(vm->ram, (champ->pc + 2) % MEM_SIZE);
	int sec = get_indirect_as_int(vm->ram, (champ->pc + 4) % MEM_SIZE);
	int reg = vm->ram[(champ->pc + 6) % MEM_SIZE];
	int s;
	byte_t *reg_start = NULL;

	if (vm == NULL || champ == NULL)
		return (-1);
	s = get_indirect_as_int(vm->ram, ((champ->pc + ind) % \
IDX_MOD) % MEM_SIZE);
	s += sec;
	reg_start = &(champ->registers[(reg - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		reg_start[i] = vm->ram[((champ->pc + s + i) % IDX_MOD) \
% MEM_SIZE];
	return (7);
}
