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

Test(vm_ld, correct_indirect_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[5] = {0x02, 0xd0, 0x00, 0x01, 0x03};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		champ->pc = instruction;
		vm_ld(vm, instruction, champ);
		cr_expect(champ->registers[2 * REG_SIZE + 0] == (byte_t)0xd0);
		cr_expect(champ->registers[2 * REG_SIZE + 1] == (byte_t)0x00);
		cr_expect(champ->registers[2 * REG_SIZE + 2] == (byte_t)0x01);
		cr_expect(champ->registers[2 * REG_SIZE + 3] == (byte_t)0x03);
		free(vm);
		free(champ);
	}
}

Test(vm_ls, correct_direct_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[7] = {0x02, 0x90, 0x0a, 0x70, 0xff, 0x01, 0x04};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		vm_ld(vm, instruction, champ);
		cr_expect(champ->registers[3 * REG_SIZE + 0] == (byte_t)0x0a);
		cr_expect(champ->registers[3 * REG_SIZE + 1] == (byte_t)0x70);
		cr_expect(champ->registers[3 * REG_SIZE + 2] == (byte_t)0xff);
		cr_expect(champ->registers[3 * REG_SIZE + 3] == (byte_t)0x01);
		free(vm);
		free(champ);
	}
}