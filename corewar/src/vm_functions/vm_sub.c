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

}

int vm_sub(vm_t *vm, byte_t *instruction, champ_t *champ)
{
	byte_t *first_from = NULL;
	byte_t *second_from = NULL;
	byte_t *to = NULL;

	if (vm == NULL || instruction == NULL || champ == NULL)
		return (-1);
	first_from = &(champ->registers[(*(instruction + 2) - 1) * REG_SIZE]);
	second_from = &(champ->registers[(*(instruction + 3) - 1) * REG_SIZE]);
	to = &(champ->registers[(*(instruction + 4) - 1) * REG_SIZE]);
	perform_sub(first_from, second_from, to);
	champ->carry = ((get_register_as_int(to) == 0) ? 1 : 0);
	return (5);
}