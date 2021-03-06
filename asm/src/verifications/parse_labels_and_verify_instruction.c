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

int set_label(char **words, assembly_data_t *data, int *curr_prog_size)
{
	int label_length = 0;
	void *fetch = NULL;

	label_length = my_strlen(words[0]);
	words[0][label_length - 1] = '\0';
	fetch = dict_fetch(data->labels, words[0]);
	if (fetch != ((void *)- 1)) {
		my_strcpy(data->error_msg, ERR_MULTIPLE_LABEL_DEFINITION);
		free(curr_prog_size);
		return (84);
	}
	dict_add(&(data->labels), words[0], curr_prog_size);
	return (0);
}

void verify_word(char *word, assembly_data_t *data, int line)
{
	label_get_t *label = NULL;

	if (is_label_get(word)) {
		label = malloc(sizeof(*label));
		label->name = my_strdup(word);
	}
	if (my_strlen(word) >= 2 && is_label_get(&(word[1]))) {
		label = malloc(sizeof(*label));
		label->name =  my_strdup(&(word[1]));
	}
	if (label == NULL)
		return;
	label->line = line;
	push(&(data->label_gets), label);
	label = NULL;
}

void parse_label_get(char **args, assembly_data_t *data, int line)
{
	char **words = NULL;

	if (args == NULL || data == NULL)
		return;
	for (int i = 0; args[i]; i++) {
		words = my_str_to_word_array(args[i], " ,");
		for (int j = 0; words[j]; j++) {
			verify_word(words[j], data, line);
		}
		free_null_terminated_word_array((void **)words);
	}
}

int parse_label_and_return_instruction_size(char *instruction, \
assembly_data_t *data, int instruction_line)
{
	char **words = my_str_to_word_array(instruction, " ");
	int *current_prog_size = NULL;
	int label_length = 0;

	if (words == NULL)
		return (-1);
	current_prog_size = malloc(sizeof(*current_prog_size));
	if (current_prog_size != NULL)
		*current_prog_size = data->header.prog_size;
	if (is_label_set(words[0]) && current_prog_size != NULL) {
		label_length = my_strlen(words[0]);
		if (set_label(words, data, current_prog_size))
			return (-1);
	} else if (current_prog_size != NULL)
		free(current_prog_size);
	parse_label_get(words, data, instruction_line);
	free_null_terminated_word_array((void **)words);
	if (instruction[label_length] != '\0')
		return (verify_instruction(&instruction[label_length], data));
	else
		return (0);
}