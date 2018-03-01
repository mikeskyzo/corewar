/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** st function of the vm
*/

/* File created the 14/02/2018 at 10:57:38 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

static int register_to_indirect(byte_t *ram, champ_t *champion)
{
	byte_t from = (ram[(champion->pc + 2) % MEM_SIZE] - 1) * REG_SIZE;
	int indirect_value = get_indirect_as_int(ram, champion->pc + 3);
	int to = 0;

	if (from > (15 * REG_SIZE))
		return (-1);
	to = champion->pc + indirect_value % IDX_MOD;
	for (int i = 0; i < REG_SIZE; i++)
		ram[(to + i) % MEM_SIZE] = champion->registers[from + i];
	return (3 + IND_SIZE);
}

static int register_to_register(byte_t *ram, champ_t *champion)
{
	byte_t from = (ram[(champion->pc + 2) % MEM_SIZE] - 1);
	byte_t to = (ram[(champion->pc + 3) % MEM_SIZE] - 1);

	if (from > 15 || to > 15)
		return (-1);
	from *= REG_SIZE;
	to *= REG_SIZE;
	for (int i = 0; i < REG_SIZE; i++)
		champion->registers[to + i] = champion->registers[from + i];
	return (4);
}

int vm_st(vm_t *vm, champ_t *champion)
{
	byte_t types = 0;

	if (vm == NULL || champion == NULL)
		return (-1);
	types = vm->ram[(champion->pc + 1) % MEM_SIZE];
	if (SECOND_PARAM_TYPE(types) == REGISTER_TYPE)
		return (register_to_register(vm->ram, champion));
	else
		return (register_to_indirect(vm->ram, champion));
	return (0);
}
