/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** the aff fonct for the vm
*/

#include "corewar.h"
#include <stdio.h>
#include "my.h"

int vm_aff(vm_t *vm, champ_t *champ)
{
	int arg = vm->ram[(champ->pc + 2) % MEM_SIZE];

	if (vm == NULL || champ == NULL)
		return (-1);
	for (int i = 0; i < REG_SIZE; i++)
		my_putchar((champ->registers[(arg - 1 + i) * REG_SIZE]) % 256);
	return (3);
}
