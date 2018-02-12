/*
** EPITECH PROJECT, 2018
** coreware
** File description:
** .h for corewar
*/

#ifndef COREWAR_H_
# define COREWAR_H_

#include "op.h"

struct champ_s
{
	header_t header;
	int nb_next_ins;
	int nb_cycle_live;
};

typedef struct champ_s chmp_t;

extern champ_t champ_tab[];

#endif
