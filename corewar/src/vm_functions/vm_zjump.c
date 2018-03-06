/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct zjump for the vm
*/

#include "corewar.h"
#include <stdlib.h>

int vm_zjmp(vm_t *vm, champ_t *champ)
{
	short arg = 0;

	if (vm == NULL || champ == NULL)
		return (-1);
	if (champ->carry == false)
		return (3);
	arg = get_indirect_as_int(vm->ram, (champ->pc + 1) % MEM_SIZE);
	champ->pc = (champ->pc + (arg % IDX_MOD));
	return (0);
}
