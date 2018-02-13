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

#define LIVE_STR "The player %d(%s) is alive.\n" /* player number/player name */
#define WON_STR "The player %d(%s) has won.\n" /* player number/player name */

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

/* Accessors */
champ_t *get_champion_by_number(vm_t *vm, int champion_nb);
champ_t *get_champion_by_name(vm_t *vm, const char *name);

/*
** Functions vm (mnemonics) prototyped as follow:
** int vm_FUNCNAME(vm_t *vm, params_you_need)
*/
int vm_live(vm_t *vm, int champion_nb);

#endif
