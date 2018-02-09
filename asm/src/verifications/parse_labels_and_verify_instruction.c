/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Parse a label if needed then verify the following instruction
*/

/* File created the 09/02/2018 at 15:00:16 by julian.frabel@epitech.eu */

#include "asm.h"
#include "op.h"

int parse_label_and_return_instruction_size(char *instruction, \
assembly_data_t *data)
{
	return (verify_instruction(instruction, data));
}