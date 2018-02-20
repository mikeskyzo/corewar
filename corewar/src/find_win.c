/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** find the winner and display
*/

#include "corewar.h"

void find_win(vm_t *vm)
{
	champ_t champ;
	int i = 0;

	for (; i < vm->nb_champ; i++)
		if (vm->champ_tab[i].alive == true)
			break;
	champ = vm->champ_tab[i];
	my_printf(WON_STR, champ.nb_prog, champ.header.prog_name);
}
