/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** sub function
*/

/* File created the 14/02/2018 at 15:24:59 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"

static void perform_sub(byte_t *from_1, byte_t *from_2, byte_t *to)
{
	int register_from_1 = get_register_as_int(from_1);
	int register_from_2 = get_register_as_int(from_2);
	int result = register_from_1 - register_from_2;

	to[0] = (result >> 24) & 0xff;
	to[1] = (result >> 16) & 0xff;
	to[2] = (result >> 8) & 0xff;
	to[3] = (result >> 0) & 0xff;
}

int vm_sub(vm_t *vm, byte_t *instruction, champ_t *champ)
{
	byte_t *first_from = NULL;
	byte_t *second_from = NULL;
	byte_t *to = NULL;

	if (vm == NULL || instruction == NULL || champ == NULL)
		return (-1);
	first_from = &(champ->registers[(vm->ram[(champ->pc + 2) % MEM_SIZE] \
- 1) * REG_SIZE]);
	second_from = &(champ->registers[(vm->ram[(champ->pc + 3) % MEM_SIZE] \
- 1) * REG_SIZE]);
	to = &(champ->registers[(vm->ram[(champ->pc + 4) % MEM_SIZE] \
- 1) * REG_SIZE]);
	perform_sub(first_from, second_from, to);
	champ->carry = ((get_register_as_int(to) == 0) ? 1 : 0);
	return (5);
}