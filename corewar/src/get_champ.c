/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** read and get the champ
*/

#include "corewar.h"
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_prog(int size, int fd)
{
	char *buffer;

	buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == NULL) {
		my_puterror("Fail to malloc\n");
		exit(84);
	}
	if (read(fd, buffer, size) == -1) {
		my_puterror("Fail to read\n");
		exit(84);
	}
	return (buffer);
}

champ_t read_champ(char *file, int *fd)
{
	champ_t champ;

	*fd = open(file, O_RDONLY);
	if (*fd == -1) {
		my_puterror("Fail to open ");
		my_puterror(file);
		my_puterror("\n");
		exit(84);
	}
	if (read(*fd, &champ.header, sizeof(champ.header)) == -1) {
		my_puterror("Fail to read\n");
		exit(84);
	}
	return (champ);
}

champ_t get_champ(char *file, int load, int nb_prog)
{
	int fd;
	champ_t champ;

	champ = read_champ(file, &fd);
	champ.prog = get_prog(champ.header.prog_size, fd);
	champ.load = load;
	champ.nb_prog = nb_prog;
	close(fd);
	return (champ);
}
