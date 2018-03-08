/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Tests for the add function
*/

/* File created the 14/02/2018 at 12:51:21 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

static void load_in_ram(vm_t *vm, byte_t *instruction, int size)
{
	for (int i = 0; i < size; i++)
		vm->ram[i] = instruction[i];
}

/* r1 : 336, r2 : 4106, r3 should be : 4442 (0x115A)->0x00 0x00 0x11 0x5a */
Test(vm_add, register_were_added_basic, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x04, 0x54, 0x01, 0x02, 0x03};

	if (vm == NULL || champion == NULL)
		cr_expect_fail();
	load_in_ram(vm, instruction, 5);
	champion->registers[0] = 0x00;
	champion->registers[1] = 0x00;
	champion->registers[2] = 0x01;
	champion->registers[3] = 0x50;
	champion->registers[4] = 0x00;
	champion->registers[5] = 0x00;
	champion->registers[6] = 0x10;
	champion->registers[7] = 0x0a;
	cr_expect(vm_add(vm, champion) == 5);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x00);
	cr_expect(champion->registers[10] == 0x11);
	cr_expect(champion->registers[11] == 0x5a);
}

Test(vm_add, register_were_added_looping, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x04, 0x54, 0x01, 0x02, 0x03};

	if (vm == NULL || champion == NULL)
		cr_expect_fail();
	load_in_ram(vm, instruction, 5);
	champion->registers[0] = 0xff;
	champion->registers[1] = 0xff;
	champion->registers[2] = 0xff;
	champion->registers[3] = 0xff;
	champion->registers[4] = 0x00;
	champion->registers[5] = 0x00;
	champion->registers[6] = 0x00;
	champion->registers[7] = 0x02;
	cr_expect(vm_add(vm, champion) == 5);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x00);
	cr_expect(champion->registers[10] == 0x00);
	cr_expect(champion->registers[11] == 0x01);
}