/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Live function of the vm
*/

/* File created the 13/02/2018 at 13:36:02 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

void set_all_live_zero(vm_t *vm, int nb)
{
	champ_t *champ;
	linked_list_t *cur = vm->programs;

	for (; cur != NULL; cur = cur->next) {
		champ = (champ_t*)cur->data;
		if (champ->nb_prog == nb)
			champ->nb_cycle_live = 0;
	}
}

int vm_live(vm_t *vm, champ_t *champion)
{
	int champion_nb = 0;

	if (vm == NULL || champion == NULL)
		return (-1);
	champion_nb = (vm->ram[(champion->pc + 1) % MEM_SIZE] << 24 | \
vm->ram[(champion->pc + 2) % MEM_SIZE] << 16 | \
vm->ram[(champion->pc + 3) % MEM_SIZE] << 8 | \
vm->ram[(champion->pc + 4) % MEM_SIZE]);
	champion = get_champion_by_number(vm, champion_nb);
	if (champion != NULL) {
		my_printf(LIVE_STR, champion_nb, champion->header.prog_name);
		set_all_live_zero(vm, champion_nb);
	} else
		my_printf(LIVE_STR, champion_nb, "unknown");
	return (5);
}
