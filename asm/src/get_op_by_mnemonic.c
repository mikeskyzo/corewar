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

int size_of_type_byte(op_t *mnemonic)
{
	if (!my_strcmp("live", mnemonic->mnemonique) || \
!my_strcmp("zjump", mnemonic->mnemonique) || \
!my_strcmp("fork", mnemonic->mnemonique) || \
!my_strcmp("lfork", mnemonic->mnemonique))
		return (0);
	return (1);
}