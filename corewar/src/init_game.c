/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** init all -> read arg/load champ/init vm
*/

#include "corewar.h"
#include <stdlib.h>

vm_t *init_game(int ac, char **av)
{
	vm_t *vm;

	vm = create_vm();
	vm->champ_tab = read_arg(av, ac, &vm->nb_champ);
	if (load_champ_all(vm, vm->champ_tab, vm->nb_champ) == -1)
		exit(84);
	return (vm);
}
