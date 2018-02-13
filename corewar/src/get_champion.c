/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Get a champion from it's informations
*/

/* File created the 13/02/2018 at 13:40:13 by julian.frabel@epitech.eu */

#include "corewar.h"
#include "my.h"

champ_t *get_champion_by_number(vm_t *vm, int champion_nb)
{
	linked_list_t *curr_index = NULL;
	champ_t *curr_champ = NULL;

	if (vm == NULL)
		return (NULL);
	curr_index = vm->programs;
	for (int i = 0; curr_index != NULL; i++) {
		curr_champ = (champ_t *)curr_index->data;
		if (curr_champ->champion_nb == champion_nb)
			return (curr_champ);
	}
	return (NULL);
}

champ_t *get_champion_by_name(vm_t *vm, const char *name)
{
	linked_list_t *curr_index = NULL;
	champ_t *curr_champ = NULL;

	if (vm == NULL || name == NULL)
		return (NULL);
	curr_index = vm->programs;
	for (int i = 0; curr_index != NULL; i++) {
		curr_champ = (champ_t *)curr_index->data;
		if (!my_strcmp(name, curr_champ->header.prog_name))
			return (curr_champ);
	}
	return (NULL);
}