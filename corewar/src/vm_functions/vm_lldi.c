/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct ldi for the vm
*/

#include "corewar.h"
#include <stdlib.h>

int vm_lldi(vm_t *vm, byte_t *instruction, champ_t *champ)
{
	int ind = get_indirect_as_int(vm->ram, champ->pc + 2);
	int sec = get_indirect_as_int(vm->ram, champ->pc + 4);
	int reg = vm->ram[(champ->pc + 6) % MEM_SIZE];
	int s;
	byte_t *reg_start = NULL;

	my_printf("%d - %d\n", ind, sec);
	if (vm == NULL || champ == NULL)
		return (-1);
	s = get_indirect_as_int(vm->ram, (champ->pc + ind) % IDX_MOD);
	s += sec;
	reg_start = &(champ->registers[(reg - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		reg_start[i] = vm->ram[(champ->pc + s + i) % MEM_SIZE];
	return (7);
}
