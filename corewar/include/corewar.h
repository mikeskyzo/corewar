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

typedef char byte_t;

struct champ_s
{
	header_t header;
	int champion_nb;
	int nb_next_ins;
	int nb_cycle_live;
	byte_t *pc;
	bool carry;
	byte_t registers[REG_SIZE * REG_NUMBER];
};

typedef struct champ_s champ_t;

struct vm_s
{
	linked_list_t *programs;
	byte_t ram[MEM_SIZE];
	int current_cycle;
	int cycle_to_die;
};

typedef struct vm_s vm_t;

/* Functions vm (mnemonics) */
int vm_live(int champion_number);

#endif
