/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** ld function of the vm
*/

/* File created the 13/02/2018 at 14:08:58 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

static int load_indirect_to_register(byte_t *ram, champ_t *champ)
{
	byte_t *register_start = NULL;
	int indirect_start = 0;
	int indirect_value = 0;
	byte_t register_nb = 0;

	if (ram == NULL || champ == NULL)
		return (-1);
	register_nb = ram[(champ->pc + 2 + IND_SIZE) % MEM_SIZE];
	if (register_nb < 1 || register_nb > REG_NUMBER)
		return (-1);
	indirect_value = get_indirect_as_int(ram, champ->pc + 2);
	indirect_start = champ->pc + indirect_value % IDX_MOD;
	register_start = &(champ->registers[(register_nb - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		register_start[i] = ram[(indirect_start + i) % MEM_SIZE];
	champ->carry = ((get_register_as_int(register_start) == 0) ? 1 : 0);
	return (0);
}

static int load_direct_to_register(byte_t *ram, champ_t *champ)
{
	byte_t *register_start = NULL;
	int direct_start = 0;
	byte_t register_nb = 0;

	if (ram == NULL || champ == NULL)
		return (-1);
	register_nb = ram[(champ->pc + 2 + DIR_SIZE) % MEM_SIZE];
	if (register_nb < 1 || register_nb > REG_NUMBER)
		return (-1);
	direct_start = (champ->pc + 2);
	register_start = &(champ->registers[(register_nb - 1) * REG_SIZE]);
	for (int i = 1; i <= MIN(REG_SIZE, DIR_SIZE); i++)
		register_start[REG_SIZE - i] = \
ram[(direct_start + DIR_SIZE - i) % MEM_SIZE];
	champ->carry = ((get_register_as_int(register_start) == 0) ? 1 : 0);
	return (0);
}

int vm_ld(vm_t *vm, byte_t *instruction_pos, champ_t *champion)
{
	byte_t types = 0;

	if (vm == NULL || instruction_pos == NULL || champion == NULL)
		return (-1);
	types = vm->ram[(champion->pc + 1) % MEM_SIZE];
	if (FIRST_PARAM_TYPE(types) == DIRECT_TYPE)
		load_direct_to_register(instruction_pos, champion);
	else
		load_indirect_to_register(instruction_pos, champion);
	return (((FIRST_PARAM_TYPE(types) == DIRECT_TYPE) ? \
3 + DIR_SIZE : 3 + IND_SIZE));
}