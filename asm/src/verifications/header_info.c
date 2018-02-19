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
	int name_cmd_len = my_strlen(NAME_CMD_STRING);
	int comment_cmd_len = my_strlen(COMMENT_CMD_STRING);

	if (!my_strncmp(instruction, NAME_CMD_STRING, name_cmd_len) && \
(instruction[name_cmd_len] == ' ' || instruction[name_cmd_len] == '\0'))
		return (1);
	if (!my_strncmp(instruction, COMMENT_CMD_STRING, comment_cmd_len) && \
(instruction[comment_cmd_len] == ' ' || instruction[comment_cmd_len] == '\0'))
		return (1);
	return (0);
}

int process_header_info(char *line, assembly_data_t *data)
{
	int name_cmd_len = my_strlen(NAME_CMD_STRING);
	int comment_cmd_len = my_strlen(COMMENT_CMD_STRING);

	if (!my_strncmp(line, NAME_CMD_STRING, name_cmd_len))
		my_strcpy(data->header.prog_name, &line[name_cmd_len + 1]);
	else
		my_strcpy(data->header.comment, &line[comment_cmd_len + 1]);
	return (0);
}