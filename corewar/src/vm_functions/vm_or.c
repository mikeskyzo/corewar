/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** or function
*/

/* File created the 15/02/2018 at 15:02:19 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"

static void set_register_value(int result, champ_t *champ, byte_t *instruction)
{
	byte_t types = *(instruction + 1);
	byte_t register_nb = *(instruction + 2 + \
SIZEOF_PARAM(FIRST_PARAM_TYPE(types)) + SIZEOF_PARAM(SECOND_PARAM_TYPE(types)));
	byte_t *reg_start = &(champ->registers[(register_nb - 1) * REG_SIZE]);

	if (register_nb > REG_NUMBER)
		return;
	reg_start[REG_SIZE - 4] = (result >> 24) & 0xff;
	reg_start[REG_SIZE - 3] = (result >> 16) & 0xff;
	reg_start[REG_SIZE - 2] = (result >> 8) & 0xff;
	reg_start[REG_SIZE - 1] = (result) & 0xff;
}

static int get_value(byte_t *instruction, champ_t *champion, int argument)
{
	byte_t types = *(instruction + 1);
	byte_t *arg = (instruction + 2 + \
(argument - 1) * SIZEOF_PARAM(FIRST_PARAM_TYPE(types)));
	byte_t argument_type = ((argument == 1) ? FIRST_PARAM_TYPE(types) : \
SECOND_PARAM_TYPE(types));

	if (argument_type == REGISTER_TYPE && *arg > REG_NUMBER)
		return (0);
	switch (argument_type) {
	case REGISTER_TYPE: return (get_register_as_int(\
&(champion->registers[((*arg) - 1) * REG_SIZE])));
	case DIRECT_TYPE: return (get_direct_as_int(arg));
	case INDIRECT_TYPE: return (get_indirect_value_as_int(\
get_indirect_as_int(arg), champion->pc));
	default: return (0);
	}
}

int vm_or(vm_t *vm, byte_t *instruction_pos, champ_t *champion)
{
	int value1 = 0;
	int value2 = 0;
	int result = 0;
	byte_t types = *(instruction_pos + 1);

	if (vm == NULL || instruction_pos == NULL || champion == NULL)
		return (-1);
	value1 = get_value(instruction_pos, champion, 1);
	value2 = get_value(instruction_pos, champion, 2);
	result = value1 | value2;
	set_register_value(result, champion, instruction_pos);
	champion->carry = !(result);
	return (3 + SIZEOF_PARAM(FIRST_PARAM_TYPE(types)) + \
SIZEOF_PARAM(SECOND_PARAM_TYPE(types)));
}