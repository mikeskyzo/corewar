/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the create vm function
*/

/* File created the 13/02/2018 at 16:24:52 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

Test(create_vm, vm_created_was_initialized)
{
	vm_t *vm = create_vm();

	if (vm != NULL) {
		cr_expect(vm->current_cycle == 0);
		cr_expect(vm->cycle_to_die == CYCLE_TO_DIE);
		cr_expect(vm->programs == NULL);
		for (int i = 0; i < MEM_SIZE; i++)
			cr_expect(vm->ram[i] == 0);
	}
}