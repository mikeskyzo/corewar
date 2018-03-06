/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fonct sti for the vm
*/

#include "corewar.h"
#include <stdlib.h>

static void get_sec_last(vm_t *vm, champ_t *champ, int *sec, int *last)
{
	byte_t types = vm->ram[(champ->pc + 1) % MEM_SIZE];
	int was_indirect = 1;

	if (SECOND_PARAM_TYPE(types) == REGISTER_TYPE) {
		*sec = get_register_as_int(&(champ->registers[\
(vm->ram[(champ->pc + 3) % MEM_SIZE] - 1) * REG_SIZE]));
		was_indirect = 0;
	} else
		*sec = get_indirect_as_int(vm->ram, (champ->pc + 3) % MEM_SIZE);
	if (THIRD_PARAM_TYPE(types) == REGISTER_TYPE) {
		*last = get_register_as_int(&(champ->registers[\
(vm->ram[(champ->pc + 4 + was_indirect) % MEM_SIZE] - 1) * REG_SIZE]));
	} else
		*last = get_indirect_as_int(vm->ram, \
(champ->pc + 4 + was_indirect) % MEM_SIZE);
}

int vm_sti(vm_t *vm, champ_t *champ)
{
	int reg;
	byte_t *reg_start = NULL;
	int sec = 0;
	int last = 0;
	byte_t types = vm->ram[(champ->pc + 1) % MEM_SIZE];

	if (vm == NULL || champ == NULL)
		return (-1);
	get_sec_last(vm, champ, &sec, &last);
	reg = vm->ram[(champ->pc + 2) % MEM_SIZE];
	if (reg < 1 || reg > REG_NUMBER)
		return (-1);
	reg_start = &(champ->registers[(reg - 1) * REG_SIZE]);
	for (int i = 0; i < REG_SIZE; i++)
		vm->ram[(champ->pc + ((sec + last) % IDX_MOD + i)) % MEM_SIZE] \
= reg_start[i];
	return (3 + SIZEOF_PARAM(SECOND_PARAM_TYPE(types)) + \
SIZEOF_PARAM(THIRD_PARAM_TYPE(types)));
}