/*
** EPITECH PROJECT, 2017
** PCE_corewar_2017
** File description:
** Verify if a file is valid or not
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include <unistd.h>

int is_comment(char *instruction)
{
	if (instruction[0] == COMMENT_CHAR)
		return (1);
	return (0);
}

int is_header_info(char *instruction)
{
	if (!my_strncmp(instruction, NAME_CMD_STRING, \
my_strlen(NAME_CMD_STRING)) && (instruction[my_strlen(NAME_CMD_STRING)] == ' ' \
|| instruction[my_strlen(NAME_CMD_STRING)] == '\0'))
		return (1);
	if (!my_strncmp(instruction, COMMENT_CMD_STRING, \
my_strlen(COMMENT_CMD_STRING)) && \
(instruction[my_strlen(COMMENT_CMD_STRING)] == ' ' \
|| instruction[my_strlen(COMMENT_CMD_STRING)] == '\0'))
		return (1);
	return (0);
}

int process_header_info(char *instruction, assembly_data_t *data)
{
	if (!my_strncmp(instruction, NAME_CMD_STRING, \
my_strlen(NAME_CMD_STRING))) {
		for (int i = 0; instruction[i + \
my_strlen(NAME_CMD_STRING) + 1] && i < PROG_NAME_LENGTH; i++)
			data->header.prog_name[i] = instruction[i + \
my_strlen(NAME_CMD_STRING) + 1];
	} else {
		for (int i = 0; instruction[i + \
my_strlen(COMMENT_CMD_STRING) + 1] && i < COMMENT_LENGTH; i++)
			data->header.prog_name[i] = instruction[i + \
my_strlen(COMMENT_CMD_STRING) + 1];
	}
	return (0);
}

int process_instruction(char *instruction, assembly_data_t *data)
{
	int size = 0;

	if (is_comment(instruction) || instruction[0] == '\0')
		return (0);
	if (is_header_info(instruction))
		process_header_info(instruction, data);
	else
		size = verify_instruction(instruction);
	if (size == -1) {
		my_puterror("Error: invalid file\n");
		return (-1);
	}
	(data->header.prog_size) += size;
	return (0);
}

int is_file_valid(int fd, assembly_data_t *data)
{
	char *instruction = NULL;
	int was_valid = 0;

	instruction = get_next_line(fd);
	while (instruction) {
		clean_str(&instruction);
		was_valid = process_instruction(instruction, data);
		free(instruction);
		if (!was_valid)
			return (0);
		instruction = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
	return (1);
}