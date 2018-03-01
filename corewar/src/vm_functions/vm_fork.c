/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** funct fork for the vm
*/

#include "corewar.h"
#include "mylist.h"
#include "my.h"
#include <stdlib.h>

void copi_champ(champ_t *champ, champ_t *new, int arg)
{
	new->header = champ->header;
	new->champion_nb = champ->champion_nb;
	new->nb_next_ins = 0;
	new->alive = true;
	new->prog = my_strdup(champ->prog);
	new->nb_prog = champ->nb_prog;
	new->load = champ->load;
	new->pc = champ->pc + arg % IDX_MOD;
	new->carry = champ->carry;
	for (int i = 0; i < REG_SIZE * REG_NUMBER; i++)
		new->registers[i] = champ->registers[i];
}

int vm_fork(vm_t *vm, champ_t *champ)
{
	champ_t *new_champ = malloc(sizeof(champ_t));
	int arg;

	if (vm == NULL || champ == NULL)
		return (-1);
	arg = get_indirect_as_int(vm->ram, (champ->pc + 1) % MEM_SIZE);
	copi_champ(champ, new_champ, arg);
	append(&(vm->programs), new_champ);
	return (3);
}
