/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Add function for the vm
*/

/* File created the 14/02/2018 at 12:49:52 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"

static byte_t perform_add(byte_t byte_1, byte_t byte_2, unsigned short *carry)
{
	unsigned short result = 0;
	unsigned short nb_1 = (unsigned short)byte_1;
	unsigned short nb_2 = (unsigned short)byte_2;

	for (int i = 1; i < my_pow(2, 8); i *= 2) {
		result = result | (((nb_1 & i) ^ (nb_2 & i)) ^ ((*carry) & i));
		if (((nb_1 & i) & (nb_2 & i)) || \
(((nb_1 & i) ^ (nb_2 & i)) & ((*carry) & i)))
			*carry = 0xffff;
		else
			*carry = 0x0000;
	}
	return (result & ((unsigned short)0x00ff));
}

int vm_add(vm_t *vm, champ_t *champ)
{
	byte_t *first_from = NULL;
	byte_t *second_from = NULL;
	byte_t *to = NULL;
	unsigned short carry = 0;

	if (vm == NULL || champ == NULL)
		return (-1);
	first_from = &(champ->registers[(vm->ram[(champ->pc + 2) % \
MEM_SIZE] - 1) * REG_SIZE]);
	second_from = &(champ->registers[(vm->ram[(champ->pc + 3) % \
MEM_SIZE] - 1) * REG_SIZE]);
	to = &(champ->registers[(vm->ram[(champ->pc + 4) % \
MEM_SIZE] -1) * REG_SIZE]);
	for (int i = REG_SIZE - 1; i >= 0; i--)
		to[i] = perform_add(first_from[i], second_from[i], &carry);
	champ->carry = ((get_register_as_int(to) == 0) ? 1 : 0);
	return (5);
}
