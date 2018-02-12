/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Verify the live instruction
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int get_type_size(int type, op_t *op)
{
	switch (type) {
		case T_REG: return (1);
		case T_DIR: return ((op->uses_ind) ? IND_SIZE : DIR_SIZE);
		case T_IND: return (IND_SIZE);
		default: return (-1);
	}
}

int get_instruction_size(char **params, op_t *op, assembly_data_t *data)
{
	char type = 0;
	int size = 0;

	if (array_size((void **)params) - 1 != op->nbr_args) {
		my_strcpy(data->error_msg, ERR_INVALID_NB_ARG);
		return (-1);
	}
	for (int i = 0; i < op->nbr_args; i++) {
		type = (is_register(params[i + 1]) | \
is_direct(params[i + 1]) | is_indirect(params[i + 1]));
		if (type & op->type[i]) {
			size += get_type_size(type, op);
			continue;
		}
		my_strcpy(data->error_msg, ERR_INVALID_ARG_TYPE);
		return (-1);
	}
	return (size);
}

int verify_instruction(char *instruction, assembly_data_t *data)
{
	char **word_tab = NULL;
	op_t *op = NULL;
	int size = 0;
	char cut[4] = " \t\0";

	if (instruction == NULL)
		return (-1);
	cut[2] = SEPARATOR_CHAR;
	word_tab = my_str_to_word_array(instruction, cut);
	if (word_tab == NULL)
		return (-1);
	op = get_op_by_mnemonic(word_tab[0]);
	if (op == NULL) {
		my_strcpy(data->error_msg, ERR_OP_NOT_FOUND);
		return (-1);
	}
	size = get_instruction_size(word_tab, op, data);
	free_null_terminated_word_array((void **)word_tab);
	return ((size != -1) ? (size + 1 + op->encode_byte) : -1);
}