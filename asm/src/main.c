/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Main function for the asm part
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"
#include "writer.h"

int main(int ac, char **av)
{
	int fd = (ac >= 1) ? open(av[1], O_RDONLY) : -1;
	assembly_data_t data = {{COREWAR_EXEC_MAGIC, {0}, 0, {0}}, \
0, 0, {0}, 0};
	int is_valid = 0;

	if (fd == -1)
		return (84);
	is_valid = is_file_valid(fd, &data);
	if (is_valid)
		writer(av[1], fd, &data);
	else
		write_error_message(&data);
	close(fd);
	dict_destroy(data.labels);
	return ((is_valid) ? 0 : 84);
}