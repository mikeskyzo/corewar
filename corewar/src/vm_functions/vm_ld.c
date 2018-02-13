/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** ld function of the vm
*/

/* File created the 13/02/2018 at 14:08:58 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

int load_indirect_to_register(byte_t *instruction_pos, champ_t *champ)
{
	byte_t *register_start = NULL;
	byte_t *indirect_start = NULL;
	int indirect_value = 0;
	byte_t register_nb = 0;

	if (instruction_pos == NULL || champ == NULL)
		return (-1);
	register_nb = *(instruction_pos + 2 + IND_SIZE);
	if (register_nb < 1 || register_nb > 16)
		return (-1);
	indirect_value = get_indirect_as_int(instruction_pos + 2);
	indirect_start = champ->pc + indirect_value % IDX_MOD;
	register_start = &(champ->registers[(register_nb - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		register_start[i] = indirect_start[i];
	return (0);
}

int load_direct_to_register(byte_t *instruction_pos, champ_t *champ)
{
	byte_t *register_start = NULL;
	byte_t *direct_start = NULL;
	byte_t register_nb = 0;

	if (instruction_pos == NULL || champ == NULL)
		return (-1);
	register_nb = *(instruction_pos + 2 + DIR_SIZE);
	if (register_nb < 1 || register_nb > 16)
		return (-1);
	direct_start = (instruction_pos + 2);
	register_start = &(champ->registers[(register_nb - 1) * REG_SIZE]);
	for (int i = 1; i <= MIN(REG_SIZE, DIR_SIZE); i++)
		register_start[REG_SIZE - i] = direct_start[DIR_SIZE - i];
	return (0);
}

int vm_ld(vm_t *vm, byte_t *instruction_pos, champ_t *champion)
{
	byte_t types = 0;

	if (vm == NULL || instruction_pos == NULL || champion == NULL)
		return (-1);
	types = *(instruction_pos + 1);
	if (FIRST_PARAM_TYPE(types) == DIRECT_TYPE)
		load_direct_to_register(instruction_pos, champion);
	else
		load_indirect_to_register(instruction_pos, champion);
	return (((FIRST_PARAM_TYPE(types) == DIRECT_TYPE) ? \
3 + DIR_SIZE : 3 + IND_SIZE));
}