/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** core_dumped display
*/

#include "my.h"
#include "corewar.h"

static int nb_len(int nb, int base_len)
{
	int len = 0;

	for (; 0 < nb; len++)
		nb /= base_len;
	return (len);
}

void display_coredump(vm_t *vm)
{
	int mem_len = nb_len(MEM_SIZE, 16);

	for (int i = 0; i < MEM_SIZE; i++) {
		if ((i % 0x20) == 0 && i == 0)
			my_printf("%-*X : ", mem_len, i);
		else if ((i % 0x20) == 0)
			my_printf("\n%-*X : ", mem_len, i);
		my_printf("%02X ", vm->ram[i]);
	}
	my_putchar('\n');
}