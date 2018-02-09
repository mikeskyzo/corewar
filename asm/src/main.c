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

void write_error_message(assembly_data_t *data)
{
	my_puterror("Error on line ");
	my_puterror_nbr(data->error_line);
	my_puterror(" :");
	my_puterror(data->error_msg);
	my_puterror("\n");
}

int main(int ac, char **av)
{
	int fd = (ac >= 1) ? open(av[1], O_RDONLY) : -1;
	int write_fd = (ac >= 2) ? open(av[2], O_RDWR) : -1;
	assembly_data_t data = {{COREWAR_EXEC_MAGIC, {0}, 0, {0}}, 0, {0}, 0};

	if (fd == -1 || write_fd == -1)
		return (84);
	if (is_file_valid(fd, &data))
		writer(write_fd, fd, &data);
	else
		write_error_message(&data);
	close(fd);
	dict_destroy(data.labels);
	return (0);
}