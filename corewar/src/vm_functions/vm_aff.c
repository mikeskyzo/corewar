/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** the aff fonct for the vm
*/

#include "corewar.h"
#include <stdio.h>
#include "my.h"

int vm_aff(vm_t *vm, byte_t *instruction_pos, champ_t *champ)
{
	int arg = vm->ram[(champ->pc + 2) % MEM_SIZE];

	if (vm == NULL || champ == NULL)
		return (-1);
	my_putchar((champ->registers[arg - 1]) % 256);
	return (0);
}
