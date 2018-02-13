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

void run_op(int fd, char *line, int *pos, assembly_data_t *datas)
{
	char **parsed_line = my_str_to_word_array(line, " ,");
	int instruct_size = 0;
	op_t op;
	int op_index;

	if (parsed_line == NULL || parsed_line[0] == NULL) {
		free_null_terminated_word_array((void **)parsed_line);
		return;
	}
	if (is_label_set(parsed_line[0]))
		label_set_manager(&parsed_line, line);
	op = get_op(parsed_line[0]);
	if (op.mnemonique == NULL) {
		free_null_terminated_word_array((void **)parsed_line);
		return;
	}
	op_index = get_op_index(op) + 1;
	write(fd, &op_index, sizeof(char));
	instruct_size += run_specific_op(fd, pos, parsed_line, datas);
	instruct_size += sizeof(char);
	*pos += instruct_size;
	free_null_terminated_word_array((void **)parsed_line);
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

int write_encode_byte(int fd, char **parsed_line)
{
	char encode = 0;
	int arg_type = -1;
	bool end_passed = false;

	if (parsed_line == NULL)
		return (0);
	for (int i = 1; i < 5; i++) {
		if (end_passed || parsed_line[i] == NULL) {
			end_passed = true;
			encode = encode << 2;
			continue;
		}
		printf("%s\n", parsed_line[i]);

		arg_type = get_arg_type(parsed_line[i]);
		if (arg_type == -1)
			continue;
		encode = encode << 2;
		encode += get_arg_type_encode(arg_type);
	}
	write(fd, &encode, sizeof(encode));
	return (sizeof(encode));
}

int run_specific_op(int fd, int *pos, char **parsed_line,\
assembly_data_t *datas)
{
	op_t op;
	char *sep_str = my_char_to_str(SEPARATOR_CHAR);
	int size = 0;
	int arg_val = 0;
	int res = 0;

	op = get_op(parsed_line[0]);
	size += sizeof(char);
	if (op.encode_byte)
		res += write_encode_byte(fd, parsed_line);
	for (int i = 1; parsed_line[i] != NULL; i++) {
		size = get_type_size(get_arg_type(parsed_line[i]), &op);
		arg_val = get_big_endians(\
get_arg_value(parsed_line[i], pos, datas), size);
		res += size;
		write(fd, &arg_val, size);
	}
	free(sep_str);
	return (res);
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