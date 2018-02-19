/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Header_infos verification
*/

/* File created the 19/02/2018 at 11:45:37 by julian.frabel@epitech.eu */

#include "my.h"
#include "asm.h"
#include "op.h"
#include "get_next_line.h"
#include <unistd.h>

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
			data->header.comment[i] = instruction[i + \
my_strlen(COMMENT_CMD_STRING) + 1];
	}
	return (0);
}