/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct zjump for the vm
*/

#include "corewar.h"
#include <stdlib.h>

int vm_zjmp(vm_t *vm, byte_t *instruction_pos, champ_t *champ)
{
	byte_t arg = vm->ram[(champ->pc + 2) % MEM_SIZE];

	if (vm == NULL || champ == NULL)
		return (-1);
	if (champ->carry == false)
		return (3);
	champ->pc += (arg % IDX_MOD);
	return (3);
}
