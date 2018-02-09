/*
** EPITECH PROJECT, 2017
** Corewar asm
** File description:
** Operators manager
*/

#include <unistd.h>
#include "my.h"
#include "asm.h"
#include "writer.h"

void run_op(int fd, char *line)
{
	char **parsed_line = my_str_to_word_array(line, " ");

	if (parsed_line[0] == NULL)
		return;
	for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
		if (my_strcmp(parsed_line[0], op_tab[i].mnemonique) == 0) {
			run_specific_op(fd, op_tab[i], i + 1, parsed_line);
		}
	}
}

void run_specific_op(int fd, op_t op, int index, char **parsed_line)
{
	char **args = my_str_to_word_array(parsed_line[1],\
my_char_to_str(SEPARATOR_CHAR));
	int size = 0;
	int arg_val = 0;

	(void)op;
	write(fd, &index, sizeof(char));
	for (int i = 0; args[i] != NULL; i++) {
		arg_val = get_arg_value(args[i]);
		size = get_arg_type_size(args[i]);
		write(fd, &arg_val, size);
	}
}

short start_with(char *str, char *start)
{
	if (my_strlen(str) < my_strlen(start))
		return (0);
	for (int i = 0; start[i] != 0; i++) {
		if (str[i] != start[i])
			return (0);
	}
	return (1);
}