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

#define MAX(value1, value2) ((value1 > value2) ? value1 : value2)
#define MIN(value1, value2) ((value1 > value2) ? value2 : value1)

/* Bits masks */
#define FIRST_PARAM_MASK	0b11000000
#define SECOND_PARAM_MASK	0b00110000
#define THIRD_PARAM_MASK	0b00001100
#define FOURTH_PARAM_MASK	0b00000011

#define REGISTER_TYPE	0b01
#define DIRECT_TYPE	0b10
#define INDIRECT_TYPE	0b11

#define FIRST_PARAM_TYPE(value) ((value & FIRST_PARAM_MASK) >> 6)
#define SECOND_PARAM_TYPE(value) ((value & SECOND_PARAM_MASK) >> 4)
#define THIRD_PARAM_TYPE(value) ((value & THIRD_PARAM_MASK) >> 2)
#define FOURTH_PARAM_TYPE(value) ((value & FOURTH_PARAM_MASK))

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

vm_t *create_vm(void);
champ_t *create_blank_champion(void);

/* Accessors */
champ_t *get_champion_by_number(vm_t *vm, int champion_nb);
champ_t *get_champion_by_name(vm_t *vm, const char *name);

int get_direct_as_int(byte_t *start);
int get_indirect_as_int(byte_t *start);

/*
** Functions vm (mnemonics) prototyped as follow:
** int vm_FUNCNAME(vm_t *vm, byte_t *instruction_pos, champ_t *champion)
** vm will be the vm and instruction_pos a pointer to the mnemonic called
** champion will be the champion that called this instruction
** the functions will return the size of himself in memory (ex live return 5)
*/
int vm_live(vm_t *vm, byte_t *instruction_pos, champ_t *champion);
int vm_ld(vm_t *vm, byte_t *instruction_pos, champ_t *champion);

#endif
