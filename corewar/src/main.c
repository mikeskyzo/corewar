/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Main function for the corewar part
*/

#include "corewar.h"
#include <stdio.h>

int main(int ac, char **av)
{
	champ_t *champ;

	ac--;
	champ = read_arg(av, ac);
	for (int i = 0; i < ac; i++)
		printf("Name : %s\nMagic : 0x%08X\nSize : %d\nComment : %s\nLoad : %d\nnb : %d\n\n", champ[i].header.prog_name, champ[i].header.magic, champ[i].header.prog_size, champ[i].header.comment, champ[i].load, champ[i].nb_prog);
	return (0);
}
