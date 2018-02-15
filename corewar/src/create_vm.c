/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Create and return a new VM
*/

/* File created the 12/02/2018 at 10:56:37 by julian.frabel@epitech.eu */

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>

vm_t *create_vm(void)
{
	vm_t *new_vm = malloc(sizeof(*new_vm));

	if (new_vm == NULL) {
		my_puterror("Could not create vm!\n");
		return (NULL);
	}
	new_vm->current_cycle = 0;
	new_vm->cycle_to_die = CYCLE_TO_DIE;
	new_vm->programs = NULL;
	for (int i = 0; i < MEM_SIZE; i++)
		new_vm->ram[i] = 0;
	return (new_vm);
}