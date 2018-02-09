/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** Writer
*/

#include <unistd.h>
#include "get_next_line.h"
#include "op.h"
#include "asm.h"
#include "writer.h"

static void write_header(int fd, header_t header);
static void write_program(int fd, int read_fd, assembly_data_t *datas);

void writer(int fd, int read_fd, assembly_data_t *datas)
{
	write_header(fd, datas->header);
	write_program(fd, read_fd, datas);
}

void write_program(int fd, int read_fd, assembly_data_t *datas)
{
	char *line = get_next_line(fd);

	(void)datas;
	while (line != NULL) {
		if (line[0] == COMMENT_CHAR)
			continue;
		run_op(read_fd, line);
		line = get_next_line(fd);
	}
}

void write_header(int fd, header_t header)
{
	write(fd, &header.magic, sizeof(header.magic));
	write(fd, &header.prog_name, sizeof(header.prog_name));
	write(fd, &header.prog_size, sizeof(header.prog_size));
	write(fd, &header.comment, sizeof(header.comment));
}