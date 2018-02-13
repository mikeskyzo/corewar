/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the get champions functions
*/

/* File created the 13/02/2018 at 17:07:38 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

Test(get_champion_by_name, champion_return_is_expected, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();

	if (vm && champion) {
		push(&(vm->programs), champion);
		cr_expect(get_champion_by_name(vm, "NONE") == NULL);
		cr_expect(get_champion_by_name(vm, NULL) == NULL);
		cr_expect(get_champion_by_name(NULL, "NONE") == NULL);
		cr_expect(get_champion_by_name(vm, "") == champion);
		free(vm);
		free(champion);
	}
}

Test(get_champion_by_number, champion_return_is_expected, .timeout=10)
{
	vm_t *vm = create_vm();
	champ_t *champion = create_blank_champion();

	if (vm && champion) {
		push(&(vm->programs), champion);
		cr_expect(get_champion_by_number(vm, 6) == NULL);
		cr_expect(get_champion_by_number(vm, -1) == NULL);
		cr_expect(get_champion_by_number(NULL, 0) == NULL);
		cr_expect(get_champion_by_number(vm, 0) == champion);
		free(vm);
		free(champion);
	}
}