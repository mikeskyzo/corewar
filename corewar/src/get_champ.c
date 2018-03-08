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

static int get_bigendian(int nb, int size)
{
	unsigned int x = 0x76543210;
	char *checker = (char *)&x;
	byte_t vm_endian_int[size];

	if (*checker == 0x76)
		return (nb);
	for (int i = 0; i < size; i++)
		vm_endian_int[i] = ((byte_t *)&nb)[size - (i + 1)];
	return (*(int *)vm_endian_int);
}

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
	champ.header.magic = get_bigendian(champ.header.magic, sizeof(int));
	champ.header.prog_size = get_bigendian(champ.header.prog_size, \
sizeof(int));
	champ.alive = true;
	return (champ);
}

champ_t get_champ(char *file, int load, int nb_prog)
{
	static int nb = 1;
	int fd;
	champ_t champ;

	champ = read_champ(file, &fd);
	champ.prog = get_prog(champ.header.prog_size, fd);
	champ.load = load;
	if (nb_prog == -1)
		champ.nb_prog = nb;
	else
		champ.nb_prog = nb_prog;
	champ.nb_next_ins = 0;
	champ.next_ins = -1;
	champ.nb_cycle_live = 0;
	champ.carry = false;
	((int *)champ.registers)[0] = get_bigendian(champ.nb_prog, sizeof(int));
	champ.next_ins = -1;
	close(fd);
	nb++;
	return (champ);
}
