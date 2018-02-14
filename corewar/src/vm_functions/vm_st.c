/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** st function of the vm
*/

/* File created the 14/02/2018 at 10:57:38 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

static int register_to_indirect(byte_t *instruction_pos, champ_t *champion)
{
	return (3 + IND_SIZE);
}

static int register_to_register(byte_t *instruction_pos, champ_t *champion)
{
	byte_t from = ((*(instruction_pos + 2)) - 1);
	byte_t to = ((*(instruction_pos + 3)) - 1);

	if (from < 0 || from > 15 || to < 0 || to > 15)
		return (-1);
	from *= REG_SIZE;
	to *= REG_SIZE;
	for (int i = 0; i < REG_SIZE; i++)
		champion->registers[to + i] = champion->registers[from + i];
	return (4);
}

int vm_st(vm_t *vm, byte_t *instruction_pos, champ_t *champion)
{
	byte_t types = 0;

	if (vm == NULL || instruction_pos == NULL || champion == NULL)
		return (-1);
	types = *(instruction_pos + 1);
	if (SECOND_PARAM_TYPE(types) == REGISTER_TYPE)
		return (register_to_register(instruction_pos, champion));
	else
		return (register_to_indirect(instruction_pos, champion));
	return (0);
}