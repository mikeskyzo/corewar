/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the ls function
*/

/* File created the 13/02/2018 at 18:00:32 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

Test(vm_ld, correct_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[2 + IND_SIZE + 1] = {0x02, 0xd0, 0x00, 0x01, 0x03};

	if (vm == NULL || champion == NULL)
		cr_assert_fail();
	else {
		champion->pc = instruction;
		vm_ld(vm, instruction, champion);
		cr_expect(champion->registers[2 * REG_SIZE + 0] == 0xd0);
		cr_expect(champion->registers[2 * REG_SIZE + 1] == 0x00);
		cr_expect(champion->registers[2 * REG_SIZE + 2] == 0x01);
		cr_expect(champion->registers[2 * REG_SIZE + 3] == 0x03);
		free(vm);
		free(champion);
	}
}