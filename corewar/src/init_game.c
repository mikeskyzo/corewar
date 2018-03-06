/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** init all -> read arg/load champ/init vm
*/

#include "corewar.h"
#include <stdlib.h>
#include "my.h"

vm_t *init_game(int ac, char **av)
{
	vm_t *vm;

	vm = create_vm();
	vm->champ_tab = read_arg(av, ac, &vm->nb_champ, &vm->dump);
	if (vm->nb_champ < 2 || vm->nb_champ > MAX_ARGS_NUMBER) {
		my_printf("Need 2 to %d champ\n", MAX_ARGS_NUMBER);
		exit(84);
	}
	if (load_champ_all(vm, vm->champ_tab, vm->nb_champ) == 84)
		exit(84);
	return (vm);
}
