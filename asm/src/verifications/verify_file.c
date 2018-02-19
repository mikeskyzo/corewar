/*
** EPITECH PROJECT, 2017
** PCE_corewar_2017
** File description:
** Verify if a file is valid or not
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include "get_next_line.h"
#include <unistd.h>

int is_comment(char *instruction)
{
	if (instruction == NULL)
		return (0);
	if (instruction[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int process_instruction(char *line, assembly_data_t *data)
{
	int size = 0;

	if (is_comment(line) || line[0] == '\0')
		return (0);
	if (is_header_info(line))
		return (process_header_info(line, data));
	size = parse_label_and_return_instruction_size(line, data);
	if (size == -1)
		return (-1);
	(data->header.prog_size) += size;
	return (0);
}

int is_file_valid(int fd, assembly_data_t *data)
{
	char *instruction = NULL;
	int was_valid = 0;

	instruction = get_next_line(fd);
	if (instruction == NULL) {
		my_strcpy(data->error_msg, ERR_EMPTY_FILE);
		return (0);
	}
	for (int i = 1; instruction; i++) {
		clean_str(&instruction);
		was_valid = !process_instruction(instruction, data);
		free(instruction);
		if (!was_valid) {
			data->error_line = i;
			return (0);
		}
		instruction = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
	return (1);
}