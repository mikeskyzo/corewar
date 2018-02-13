/*
** EPITECH PROJECT, 2017
** Corewar asm
** File description:
** Label set manager
*/

#include "my.h"

void label_set_manager(char ***parsed_line, char *line)
{
	int size = 0;
	char **new_parsed_line = NULL;

	for (size = 0; line[size] != ':' && line[size] != 0; size++);
	line = &line[size + 1];
	new_parsed_line = my_str_to_word_array(line, " ,");
	if (new_parsed_line == NULL)
		return;
	free_null_terminated_word_array((void **)*parsed_line);
	*parsed_line = new_parsed_line;
}