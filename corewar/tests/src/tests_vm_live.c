/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** test the vm_live
*/

/* File created the 13/02/2018 at 17:28:14 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void load_in_ram(vm_t *vm, byte_t *instruction, int size)
{
	for (int i = 0; i < size; i++)
		vm->ram[i] = instruction[i];
}

void redirect_all(void)
{
	cr_redirect_stderr();
	cr_redirect_stdout();
}

Test(vm_live, correct_champion, .init=redirect_all, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();
	byte_t instruction[5] = {0x01, 0x00, 0x00, 0x00, 0x01};

	if (vm == NULL || champion == NULL)
		cr_assert_fail();
	load_in_ram(vm, instruction, 5);
	champion->nb_prog = 1;
	champion->header.prog_name[0] = 'A';
	champion->pc = 0;
	append(&(vm->programs), champion);
	cr_assert(vm_live(vm, champion) == 5);
	cr_expect_stdout_eq_str("The player 1(A) is alive.\n");
	free(vm);
	free(champion);
}

Test(vm_live, incorrect_champion, .init=redirect_all, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champ = create_blank_champion();
	byte_t instruction[5] = {0x01, 0x00, 0x00, 0x00, 0x01};

	if (vm == NULL)
		cr_assert_fail();
	load_in_ram(vm, instruction, 5);
	cr_assert(vm_live(NULL, NULL) == -1);
	cr_assert(vm_live(NULL, NULL) == -1);
	cr_assert(vm_live(vm, NULL) == -1);
	cr_assert(vm_live(vm, NULL) == -1);
	cr_assert(vm_live(vm, champ) == 5);
	cr_expect_stdout_eq_str("The player 1(unknown) is alive.\n");
	free(vm);
	free(champ);
}