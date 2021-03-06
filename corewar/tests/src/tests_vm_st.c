/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the st function
*/

/* File created the 14/02/2018 at 11:00:13 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

static void load_in_ram(vm_t *vm, byte_t *instruction, int size)
{
	for (int i = 0; i < size; i++)
		vm->ram[i] = instruction[i];
}

Test(vm_st, register_to_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[4] = {0x03, 0x50, 0x01, 0x02};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		load_in_ram(vm, instruction, 4);
		champ->registers[0] = (byte_t)0xd0;
		champ->registers[1] = (byte_t)0x00;
		champ->registers[2] = (byte_t)0x01;
		champ->registers[3] = (byte_t)0x03;
		cr_expect(vm_st(vm, champ) == 4);
		cr_expect(champ->registers[1 * REG_SIZE + 0] == (byte_t)0xd0);
		cr_expect(champ->registers[1 * REG_SIZE + 1] == (byte_t)0x00);
		cr_expect(champ->registers[1 * REG_SIZE + 2] == (byte_t)0x01);
		cr_expect(champ->registers[1 * REG_SIZE + 3] == (byte_t)0x03);
		free(vm);
		free(champ);
	}
}

Test(vm_st, register_to_indirect, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[5] = {0x03, 0x70, 0x01, 0x00, 0x01};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		load_in_ram(vm, instruction, 5);
		champ->registers[0] = (byte_t)0xd0;
		champ->registers[1] = (byte_t)0x00;
		champ->registers[2] = (byte_t)0x01;
		champ->registers[3] = (byte_t)0x03;
		cr_expect(vm_st(vm, champ) == 5);
		cr_expect(vm->ram[1] == (byte_t)0xd0);
		cr_expect(vm->ram[2] == (byte_t)0x00);
		cr_expect(vm->ram[3] == (byte_t)0x01);
		cr_expect(vm->ram[4] == (byte_t)0x03);
		free(vm);
		free(champ);
	}
}