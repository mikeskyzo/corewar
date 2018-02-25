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
	byte_t second = vm->ram[(champ->pc + 4) % MEM_SIZE];
	byte_t last = vm->ram[(champ->pc + 6) % MEM_SIZE];

	if (vm == NULL || champ == NULL)
		return (-1);
	reg = vm->ram[champ->pc + 2 % MEM_SIZE];
	vm->ram[((champ->pc + second + last) % IDX_MOD) % MEM_SIZE] = \
champ->registers[reg];
	return (7);
}
