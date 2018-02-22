/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** start all the game
*/

#include "corewar.h"
#include "my.h"

int nb_champ_alive(champ_t *champ_tab, int nb_champ)
{
	int nb_alive = 0;

	for (int i = 0; i < nb_champ; i++)
		if (champ_tab[i].alive == true)
			nb_alive++;
	return (nb_alive);
}

champ_t *update_champ(champ_t *champ, int nb_champ)
{
	for (int i = 0; i < nb_champ; i++) {
		champ[i].nb_cycle_live++;
		if (champ[i].nb_cycle_live > CYCLE_TO_DIE)
			champ[i].alive = false;
		if (champ[i].nb_next_ins > 0)
			champ[i].nb_next_ins--;
	}
	return (champ);
}

void loop_game(vm_t *vm, champ_t champ)
{
	if (champ.alive == false || champ.nb_next_ins > 0)
		return;
}

void start_game(vm_t *vm)
{
	while (nb_champ_alive(vm->champ_tab, vm->nb_champ) > 1) {
		vm->champ_tab = update_champ(vm->champ_tab, vm->nb_champ);
		for (int i = 0; i < vm->nb_champ; i++) {
			loop_game(vm, vm->champ_tab[i]);
		}
	}
	find_win(vm);
}
