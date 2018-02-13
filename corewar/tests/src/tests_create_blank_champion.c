/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the create_blank_champion function
*/

/* File created the 13/02/2018 at 17:01:18 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

Test(create_blank_champion, champion_is_initialized, .timeout=10)
{
	champ_t *champ = create_blank_champion();

	if (champ) {
		cr_expect(champ->carry == 0);
		cr_expect(champ->champion_nb == 0);
		cr_expect(champ->header.magic == 0);
		cr_expect(champ->header.prog_size == 0);
		for (int i = 0; i < PROG_NAME_LENGTH; i++)
			cr_expect(champ->header.prog_name[i] == 0);
		for (int i = 0; i < COMMENT_LENGTH; i++)
			cr_expect(champ->header.comment[i] == 0);
		cr_expect(champ->nb_cycle_live == 0);
		cr_expect(champ->nb_next_ins == 0);
		cr_expect(champ->pc == 0);
		for (int i = 0; i < REG_NUMBER * REG_SIZE; i++)
			cr_expect(champ->registers[i] == 0);
		free(champ);
	}
}