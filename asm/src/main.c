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
#include "match.h"
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

static char *get_write_name(char *base_name)
{
	int size = 0;
	char **arr = my_str_to_word_array(base_name, "/");
	char *res = NULL;

	if (arr == NULL)
		return (base_name);
	res = my_strdup(arr[array_size((void **)arr) - 1]);
	if (res == NULL)
		return (base_name);
	size = my_strlen(res);
	if (match(res, "*.s")) {
		res[size - 1] = 0;
		my_strdupcat(&res, "cor");
		return (res);
	}
	my_strdupcat(&res, ".cor");
	free_null_terminated_word_array((void *)arr);
	return (res);
}

int main(int ac, char **av)
{
	int fd = (ac >= 1) ? open(av[1], O_RDONLY) : -1;
	char *file_name = (ac >= 1) ? get_write_name(av[1]) : "file";
	int write_fd = (ac >= 1) ? open(file_name, O_CREAT | O_RDWR, 0755) : -1;
	assembly_data_t data = {{COREWAR_EXEC_MAGIC, {0}, 0, {0}}, 0, {0}, 0};
	int is_valid = 0;

	free(file_name);
	if (fd == -1 || write_fd == -1)
		return (84);
	is_valid = is_file_valid(fd, &data);
	if (is_valid)
		writer(write_fd, fd, &data);
	else
		write_error_message(&data);
	close(fd);
	dict_destroy(data.labels);
	return ((is_valid) ? 0 : 84);
}