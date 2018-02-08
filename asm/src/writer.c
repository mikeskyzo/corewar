/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** Writer
*/

#include <unistd.h>
#include "op.h"

static void write_header(int fd, header_t header);

void writer(char *str, int fd, assembly_data_t *datas)
{
	write_header(fd, datas->header);
}

void write_header(int fd, header_t header)
{
	write(fd, header.magic, sizeof(header.magic));
	write(fd, header.prog_name, sizeof(header.prog_name));
	write(fd, header.prog_size, sizeof(header.prog_size));
	write(fd, header.comment, sizeof(header.comment));
}