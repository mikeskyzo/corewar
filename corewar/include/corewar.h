/*
** EPITECH PROJECT, 2018
** coreware
** File description:
** .h for corewar
*/

#ifndef COREWAR_H_
# define COREWAR_H_

#include "op.h"
#include "mylist.h"

#define BYTE char

struct champ_s
{
	header_t header;
	int nb_next_ins;
	int nb_cycle_live;
	BYTE *pc;
	bool carry;
	BYTE registers[REG_SIZE * REG_NUMBER];
};

typedef struct champ_s champ_t;

struct vm_s
{
	linked_list_t *programs;
	BYTE ram[MEM_SIZE];
	int current_cycle;
	int cycle_to_die;
};

typedef struct vm_s vm_t;

extern champ_t champ_tab[];

#endif
