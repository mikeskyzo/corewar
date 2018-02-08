/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Main function for the asm part
*/

#include "my.h"
#include "asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int fd = (ac >= 1) ? open(av[1], O_RDONLY) : -1;
	assembly_data_t data = {{COREWAR_EXEC_MAGIC, {0}, 0, {0}}, NULL, {0}};

	if (fd == -1)
		return (84);
	if (is_file_valid(fd, &data)) {
		my_printf("File is valid\n");
		my_printf("Champ name: %s, champ description: %s, size: %i\n", data.header.prog_name, data.header.comment, data.header.prog_size);
	} else
		my_printf("File is invalid\n");
	close(fd);
	return (0);
}