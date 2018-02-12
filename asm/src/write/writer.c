/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** Writer
*/

#include <unistd.h>
#include "my.h"
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
	char *line = get_next_line(read_fd);
	int pos = 0;

	(void)datas;
	while (line != NULL) {
		clean_str(&line);
		if (line[0] != COMMENT_CHAR) {
			run_op(fd, line, &pos, datas);
		}
		free(line);
		line = get_next_line(read_fd);
	}
}

void write_header(int fd, header_t header)
{
	header.magic = header.magic, 4;
	header.prog_size = header.prog_size, 4;
	write(fd, &header, sizeof(header));
}

int get_big_endians(int val, int size)
{
	unsigned int x = 0x76543210;
	char *checker = (char *)&x;
	int b0 = (val & 0xff) << 24;
	int b1 = (val & 0xff00) << 8;
	int b2 = (val & 0xff0000) >> 8;
	int b3 = (val & 0xff000000) >> 24;
	int res = b0 | b1 | b2 | b3;

	if (*checker == 0x76)
		return (val);
	switch (size) {
		case 1: return (val);
		case 2:	return ((val >> 8) | (val & 0xff) << 8);
		case 3: return (val);
		case 4: return (b0 | b1 | b2 | b3);
	}
	return (res);
}