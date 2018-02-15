/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Create and return a new blank champion
*/

/* File created the 13/02/2018 at 16:54:55 by julian.frabel@epitech.eu */

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

champ_t *create_blank_champion(void)
{
	champ_t *new_champ = malloc(sizeof(*new_champ));

	if (new_champ == NULL)
		return (NULL);
	new_champ->carry = 0;
	new_champ->champion_nb = 0;
	new_champ->header = (header_t){0, {0}, 0, {0}};
	new_champ->nb_cycle_live = 0;
	new_champ->nb_next_ins = 0;
	new_champ->pc = 0;
	for (int i = 0; i < REG_SIZE * REG_NUMBER; i++)
		new_champ->registers[i] = 0;
	return (new_champ);
}