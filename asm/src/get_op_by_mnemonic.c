/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Get an op_t by it's mnemonic
*/

#include "my.h"
#include "op.h"
#include <unistd.h>

op_t *get_op_by_mnemonic(char *mnemonique)
{
	for (int i = 0; op_tab[i].mnemonique; i++) {
		if (!my_strcmp(mnemonique, op_tab[i].mnemonique))
			return (&op_tab[i]);
	}
	return (NULL);
}