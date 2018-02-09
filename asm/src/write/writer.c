/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** Writer
*/

#include <unistd.h>
#include "op.h"
#include "asm.h"

static void write_header(int fd, header_t header);

void writer(int fd, assembly_data_t *datas)
{
	write_header(fd, datas->header);
	write_program(fd, datas);
}

void write_program(int fd, assembly_data_t *datas)
{
	char *line = get_next_line(0);

	while (line != NULL) {
		if (line[0] == COMMENT_CHAR)
			continue;
		run_op(fd, line);
		line = get_next_line(0);
	}
}

void write_header(int fd, header_t header)
{
	write(fd, header.magic, sizeof(header.magic));
	write(fd, header.prog_name, sizeof(header.prog_name));
	write(fd, header.prog_size, sizeof(header.prog_size));
	write(fd, header.comment, sizeof(header.comment));
}