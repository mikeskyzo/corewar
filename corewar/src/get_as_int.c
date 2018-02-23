/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Get an direct/indirect as an int
*/

/* File created the 13/02/2018 at 15:32:45 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"

int get_register_as_int(byte_t *ram)
{
	int result = 0;

	if (ram == NULL)
		return (0);
	for (int i = 0; i < REG_SIZE; i++)
		result = (result << 8) | (ram[i]);
	return (result);
}

int get_direct_as_int(byte_t *ram, int start)
{
	int result = 0;

	if (ram == NULL)
		return (0);
	for (int i = 0; i < DIR_SIZE; i++)
		result = (result << 8) | (ram[(i + start) % MEM_SIZE]);
	return (result);
}

int get_indirect_as_int(byte_t *ram, int start)
{
	int result = 0;

	if (ram == NULL)
		return (0);
	for (int i = 0; i < IND_SIZE; i++)
		result = (result << 8) | (ram[(i + start) % MEM_SIZE]);
	return (result);
}

int get_indirect_value_as_int(int indirect, byte_t *ram, int pc)
{
	int result = 0;

	if (pc == NULL)
		return (0);
	for (int i = 0; i < 4; i++)
		result = (result << 8) | \
(ram[(pc + (indirect + i) % IDX_MOD) % MEM_SIZE]);
	return (result);
}