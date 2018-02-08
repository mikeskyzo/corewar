/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Verify the live instruction
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int get_instruction_size(char **params, op_t *op)
{
	return (0);
}

int verify_instruction(char *instruction)
{
	char **word_tab = NULL;
	op_t *op = NULL;
	int size = 0;
	char cut[3] = " \t\0";

	if (instruction == NULL)
		return (-1);
	cut[2] = SEPARATOR_CHAR;
	word_tab = my_str_to_word_array(instruction, cut);
	if (word_tab == NULL)
		return (-1);
	op = get_op_by_mnemonic(word_tab[0]);
	if (op == NULL)
		return (-1);
	size = get_instruction_size(word_tab, op);
	free_null_terminated_word_array((void **)word_tab);
	return (size);
}