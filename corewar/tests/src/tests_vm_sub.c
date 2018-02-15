/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the vm_sub function
*/

/* File created the 14/02/2018 at 15:18:19 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

/* r1 : 4106, r2 : 336, r3 should be : 3770 (0xEBA)->0x00 0x00 0x0e 0xba */
Test(vm_sub, register_were_substracted_basic, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x05, 0x54, 0x01, 0x02, 0x03};

	if (vm == NULL || champion == NULL)
		cr_expect_fail();
	champion->registers[0] = 0x00;
	champion->registers[1] = 0x00;
	champion->registers[2] = 0x10;
	champion->registers[3] = 0x0a;
	champion->registers[4] = 0x00;
	champion->registers[5] = 0x00;
	champion->registers[6] = 0x01;
	champion->registers[7] = 0x50;
	cr_expect(vm_sub(vm, instruction, champion) == 5);
	cr_expect(champion->registers[8] == 0x00);
	cr_expect(champion->registers[9] == 0x00);
	cr_expect(champion->registers[10] == 0x0e);
	cr_expect(champion->registers[11] == 0xba);
}

Test(vm_sub, register_were_substracted_looping, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x05, 0x54, 0x01, 0x02, 0x03};

	if (vm == NULL || champion == NULL)
		cr_expect_fail();
	champion->registers[0] = 0x00;
	champion->registers[1] = 0x00;
	champion->registers[2] = 0x00;
	champion->registers[3] = 0x02;
	champion->registers[4] = 0x00;
	champion->registers[5] = 0x00;
	champion->registers[6] = 0x00;
	champion->registers[7] = 0x04;
	cr_expect(vm_sub(vm, instruction, champion) == 5);
	cr_expect(champion->registers[8] == 0xff);
	cr_expect(champion->registers[9] == 0xff);
	cr_expect(champion->registers[10] == 0xff);
	cr_expect(champion->registers[11] == 0xfe);
}