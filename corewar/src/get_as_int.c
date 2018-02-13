/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Get an direct/indirect as an int
*/

/* File created the 13/02/2018 at 15:32:45 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"

int get_direct_as_int(byte_t *start)
{
	int result = 0;

	if (start == NULL)
		return (0);
	for (int i = 0; i < DIR_SIZE; i++)
		result = (result << 8) | (start[i]);
	return (result);
}

int get_indirect_as_int(byte_t *start)
{
	int result = 0;

	if (start == NULL)
		return (0);
	for (int i = 0; i < IND_SIZE; i++)
		result = (result << 8) | (start[i]);
	return (result);
}