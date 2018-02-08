/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Verify the live instruction
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int verif_live(char *instruction)
{
	if (my_strncmp("live ", instruction, 5))
		return (-1);
}