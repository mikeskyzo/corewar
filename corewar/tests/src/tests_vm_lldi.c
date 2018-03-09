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

Test(vm_lldi, correct_indirect_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[7] = \
{0x0a, 0xf4, 0x00, 0x01, 0x01, 0x04, 0x01};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		load_in_ram(vm, instruction, 7);
		vm_lldi(vm, champ);
		cr_expect(champ->registers[0] == (byte_t)0x00);
		cr_expect(champ->registers[1] == (byte_t)0x00);
		cr_expect(champ->registers[2] == (byte_t)0x00);
		cr_expect(champ->registers[3] == (byte_t)0x00);
		free(vm);
		free(champ);
	}
}

Test(vm_lldi, correct_direct_register, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[7] = \
{0x0a, 0xa4, 0x00, 0x01, 0x01, 0x04, 0x01};

	if (vm == NULL || champ == NULL)
		cr_assert_fail();
	else {
		load_in_ram(vm, instruction, 7);
		champ->pc = 0;
		vm_lldi(vm, champ);
		cr_expect(champ->registers[0] == (byte_t)0x00);
		cr_expect(champ->registers[1] == (byte_t)0x00);
		cr_expect(champ->registers[2] == (byte_t)0x01);
		cr_expect(champ->registers[3] == (byte_t)0x05);
		free(vm);
		free(champ);
	}
}