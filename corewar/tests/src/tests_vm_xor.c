/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the vm_xor function
*/

/* File created the 15/02/2018 at 14:56:10 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

static void load_in_ram(vm_t *vm, byte_t *instruction, int size)
{
	for (int i = 0; i < size; i++)
		vm->ram[i] = instruction[i];
}

Test(vm_xor, perform_and_with_registers, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x06, 0x54, 0x01, 0x02, 0x03};

	load_in_ram(vm, instruction, 5);
	champion->registers[0] = 0x00;
	champion->registers[1] = 0x40;
	champion->registers[2] = 0xab;
	champion->registers[3] = 0x33;
	champion->registers[4] = 0x90;
	champion->registers[5] = 0xd0;
	champion->registers[6] = 0x06;
	champion->registers[7] = 0x66;
	champion->pc = 0;
	cr_expect(vm_xor(vm, champion) == 5);
	cr_expect(champion->registers[8] == 0x90);
	cr_expect(champion->registers[9] == 0x90);
	cr_expect(champion->registers[10] == 0xad);
	cr_expect(champion->registers[11] == 0x55);
}

Test(vm_xor, perform_and_with_directs, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[11] = {0x06, 0xa4, 0x00, 0x40, 0xab, 0x33, \
0x90, 0xd0, 0x06, 0x66, 0x03};

	load_in_ram(vm, instruction, 11);
	champion->pc = 0;
	cr_expect(vm_xor(vm, champion) == 11);
	cr_expect(champion->registers[8] == 0x90);
	cr_expect(champion->registers[9] == 0x90);
	cr_expect(champion->registers[10] == 0xad);
	cr_expect(champion->registers[11] == 0x55);
}

Test(vm_xor, perform_and_with_indirects, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[7] = {0x06, 0xf4, 0x00, 0x01, 0x00, 0x02, 0x03};

	load_in_ram(vm, instruction, 7);
	champion->pc = 0;
	cr_expect(vm_xor(vm, champion) == 7);
	cr_expect(champion->registers[8] == 0xf4);
	cr_expect(champion->registers[9] == 0x01);
	cr_expect(champion->registers[10] == 0x01);
	cr_expect(champion->registers[11] == 0x02);
}

Test(vm_xor, mixed_register_direct, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[] = {0x06, 0x64, 0x01, 0x33, 0x90, 0x66, 0xd0, 0x03};

	load_in_ram(vm, instruction, 8);
	champion->registers[0] = 0x44;
	champion->registers[1] = 0xff;
	champion->registers[2] = 0x84;
	champion->registers[3] = 0xfa;
	champion->pc = 0;
	cr_expect(vm_xor(vm, champion) == 8);
	cr_expect(champion->registers[8] == 0x77);
	cr_expect(champion->registers[9] == 0x6f);
	cr_expect(champion->registers[10] == 0xe2);
	cr_expect(champion->registers[11] == 0x2a);
}

Test(vm_xor, mixed_direct_indirect, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[9] = {0x06, 0xb4, 0x09, 0x55, 0x33, 0x44, \
0x00, 0x02, 0x01};

	load_in_ram(vm, instruction, 9);
	champion->pc = 0;
	cr_expect(vm_xor(vm, champion) == 9);
	cr_expect(champion->registers[0] == 0x00);
	cr_expect(champion->registers[1] == 0x00);
	cr_expect(champion->registers[2] == 0x00);
	cr_expect(champion->registers[3] == 0x00);
}