/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Main function for the asm part
*/

#include "my.h"
#include "asm.h"
#include <sys/types.h>
#include <sys.stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	assembly_data_t data = {{COREWAR_EXEC_MAGIC, {0}, 0, {0}}, NULL};

	if (fd == -1)
		return (84);
	if (is_file_valid(fd, &data))
		my_printf("File is valid\n");
	else
		my_printf("File is invalid\n");
	close(fd);
	return (0);
}