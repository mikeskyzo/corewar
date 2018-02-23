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
	vm_t *vm;

	vm = init_game(ac, av);
	start_game(vm);
	return (0);
}
