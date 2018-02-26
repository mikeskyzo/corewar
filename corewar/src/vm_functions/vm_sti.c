/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct sti for the vm
*/

#include "corewar.h"
#include <stdlib.h>

int vm_sti(vm_t *vm, byte_t *instruction, champ_t *champ)
{
	int reg;
	byte_t *reg_start = NULL;
	byte_t sec = get_indirect_as_int(vm->ram ,(champ->pc + 3) % MEM_SIZE);
	byte_t last = get_indirect_as_int(vm->ram ,(champ->pc + 5) % MEM_SIZE);

	if (vm == NULL || champ == NULL)
		return (-1);
	reg = vm->ram[(champ->pc + 2) % MEM_SIZE];
	if (reg < 1 || reg > REG_NUMBER)
		return (-1);
	reg_start = &(champ->registers[(reg - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		vm->ram[((champ->pc + sec + last + i) % IDX_MOD) % MEM_SIZE] = \
reg_start[i];
	return (7);
}
