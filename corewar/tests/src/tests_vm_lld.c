/*
** EPITECH PROJECT, 2018
** Coreware UTs
** File description:
** lld func UTs
*/

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

static void load_in_ram(vm_t *vm, byte_t *instruction, int size)
{
	for (int i = 0; i < size; i++)
		vm->ram[i] = instruction[i];
}

Test(vm_lld, correct_indirect_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[5] = {0x0d, 0xd0, 0x00, 0x01, 0x03};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		load_in_ram(vm, instruction, 5);
		vm_lld(vm, champ);
		cr_expect(champ->registers[2 * REG_SIZE + 0] == (byte_t)0xd0);
		cr_expect(champ->registers[2 * REG_SIZE + 1] == (byte_t)0x00);
		cr_expect(champ->registers[2 * REG_SIZE + 2] == (byte_t)0x01);
		cr_expect(champ->registers[2 * REG_SIZE + 3] == (byte_t)0x03);
		free(vm);
		free(champ);
	}
}

Test(vm_lld, correct_direct_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[7] = {0x0d, 0x90, 0x0a, 0x70, 0xff, 0x01, 0x04};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		load_in_ram(vm, instruction, 7);
		vm_lld(vm, champ);
		cr_expect(champ->registers[3 * REG_SIZE + 0] == (byte_t)0x0a);
		cr_expect(champ->registers[3 * REG_SIZE + 1] == (byte_t)0x70);
		cr_expect(champ->registers[3 * REG_SIZE + 2] == (byte_t)0xff);
		cr_expect(champ->registers[3 * REG_SIZE + 3] == (byte_t)0x01);
		free(vm);
		free(champ);
	}
}