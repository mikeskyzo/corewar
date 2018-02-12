/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Parse a label if needed then verify the following instruction
*/

/* File created the 09/02/2018 at 15:00:16 by julian.frabel@epitech.eu */

#include "my.h"
#include "asm.h"
#include "op.h"
#include "mylist.h"

int parse_label_and_return_instruction_size(char *instruction, \
assembly_data_t *data)
{
	char **words = my_str_to_word_array(instruction, " ");
	int label_length = 0;
	int *current_prog_size = malloc(sizeof(*current_prog_size));

	if (words == NULL || current_prog_size == NULL)
		return (-1);
	*current_prog_size = data->header.prog_size;
	if (is_label_set(words[0])) {
		label_length = my_strlen(words[0]);
		words[0][label_length - 1] = '\0';
		dict_add(&(data->labels), words[0], current_prog_size);
	}
	free_null_terminated_word_array((void **)words);
	if (instruction[label_length] != '\0')
		return (verify_instruction(&instruction[label_length], data));
	else
		return (0);
}