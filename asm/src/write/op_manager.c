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

char get_arg_type_encode(int arg_type)
{
	switch (arg_type) {
		case T_REG:
			return (0b01);
		case T_DIR:
			return (0b10);
		case T_IND:
			return (0b11);
	}
	return (0);
}

void write_encode_byte(int fd, char **args)
{
	char encode = 0;
	int arg_type = -1;

	for (int i = 0; i < 4; i++) {
		if (args[i] == NULL) {
			encode = encode << 2;
			continue;
		}
		arg_type = get_arg_type(args[i]);
		encode = encode << 2;
		encode += get_arg_type_encode(arg_type);
	}
	write(fd, &encode, sizeof(encode));
}

void run_specific_op(int fd, op_t op, int index, char **parsed_line)
{
	char **args = my_str_to_word_array(parsed_line[1],\
my_char_to_str(SEPARATOR_CHAR));
	int size = 0;
	int arg_val = 0;

	(void)op;
	write(fd, &index, sizeof(char));
	if (op.encode_byte)
		write_encode_byte(fd, args);
	for (int i = 0; args[i] != NULL; i++) {
		size = get_type_size(get_arg_type(args[i]), &op);
		arg_val = get_big_endians(get_arg_value(args[i]), size);
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