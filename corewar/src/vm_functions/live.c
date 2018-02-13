/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Live function of the vm
*/

/* File created the 13/02/2018 at 13:36:02 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

int vm_live(vm_t *vm, int champion_nb)
{
	champ_t *champion = get_champion_by_number(vm, champion_nb);

	if (champion)
		my_printf(LIVE_STR, champion_nb, champion->header.prog_name);
	else
		my_printf(LIVE_STR, champion_nb, "unknown");
	return (0);
}