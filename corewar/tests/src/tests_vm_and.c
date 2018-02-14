/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the and function
*/

/* File created the 14/02/2018 at 17:10:36 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

Test(vm_and, perform_and_with_registers, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x06, 0x54, 0x01, 0x02, 0x03};

	champion->registers[0] = 0x00;
	champion->registers[1] = 0x40;
	champion->registers[2] = 0xab;
	champion->registers[3] = 0x33;
	champion->registers[4] = 0x90;
	champion->registers[5] = 0xd0;
	champion->registers[6] = 0x06;
	champion->registers[7] = 0x66;
	cr_expect(vm_and(vm, instruction, champion) == 5);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x40);
	cr_expect(champion->registers[10] == 0x02);
	cr_expect(champion->registers[11] == 0x22);
}

Test(vm_and, perform_and_with_directs, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[11] = {0x06, 0xa4, 0x00, 0x40, 0xab, 0x33, \
0x90, 0xd0, 0x06, 0x66, 0x03};

	cr_expect(vm_and(vm, instruction, champion) == 11);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x40);
	cr_expect(champion->registers[10] == 0x02);
	cr_expect(champion->registers[11] == 0x22);
}

Test(vm_and, perform_and_with_indirects, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[7] = {0x06, 0xf4, 0x00, 0x01, 0x00, 0x02, 0x03};

	cr_expect(vm_and(vm, instruction, champion) == 7);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x00);
	cr_expect(champion->registers[10] == 0x00);
	cr_expect(champion->registers[11] == 0x00);
}

Test(vm_and, mixed_register_direct, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[] = {0x06, 0x64, 0x01, 0x33, 0x90, 0x66, 0xd0, 0x03};

	champion->registers[0] = 0x44;
	champion->registers[1] = 0xff;
	champion->registers[2] = 0x84;
	champion->registers[3] = 0xfa;
	cr_expect(vm_and(vm, instruction, champion) == 8);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x90);
	cr_expect(champion->registers[10] == 0x04);
	cr_expect(champion->registers[11] == 0xd0);
}

Test(vm_and, mixed_direct_indirect, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[9] = {0x06, 0xb4, 0x09, 0x55, 0x33, 0x44, \
0x00, 0x02, 0x01};

	cr_expect(vm_and(vm, instruction, champion) == 9);
	cr_expect(champion->registers[0] == 0x09);
	cr_expect(champion->registers[1] == 0x55);
	cr_expect(champion->registers[2] == 0x33);
	cr_expect(champion->registers[3] == 0x44);
}