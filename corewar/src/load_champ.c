/*
** EPITECH PROJECT, 2018
** corewar 2017
** File description:
** load champion in vm's ram fx
*/

#include "my.h"
#include "corewar.h"

static int compute_spacement(champ_t *tab, int champ_nb)
{
	int tot_size = 0;

	for (int i = 0; i < champ_nb; i++)
		tot_size += tab[i].header.prog_size;
	if (MEM_SIZE < tot_size)
		return (-1);
	else
		return (tot_size / champ_nb);
}

static int compute_rampos(champ_t *champ_tab, int champ_ind, int champ_nb)
{
	int spacement = compute_spacement(champ_tab, champ_nb);
	int rampos = 0;

	if (spacement < 0)
		return (-1);
	for (int i = 0; i < champ_ind; i++)
		rampos += spacement + champ_tab[i].header.prog_size;
	return (rampos);
}

static int load_in_ram(vm_t *vm, champ_t *champ, unsigned int ram_pos)
{
	champ->pc = &(vm->ram[ram_pos]);
	for (int i = 0; i < champ->header.prog_size; i++)
		if (vm->ram[(ram_pos + i) % MEM_SIZE] != 0)
			return (84);
		else
			vm->ram[(ram_pos + i) % MEM_SIZE] = champ->prog[i];
	return (0);
}

int load_champ(vm_t *vm, champ_t *champ, int champ_ind, int champ_nb)
{
	int rampos = compute_rampos(champ, champ_ind, champ_nb);

	if (rampos < 0)
		return (-1);
	load_in_ram(vm, &(champ[champ_ind]), rampos);
	return (0);
}

int load_champ_all(vm_t *vm, champ_t *champ, int champ_nb)
{
	int rampos = 0;

	for (int i = 0; i < champ_nb; i++) {
		if ((champ[i]).load < 0)
			rampos = compute_rampos(champ, i, champ_nb);
		else
			rampos = (champ[i]).load;
		if (rampos < 0)
			return (84);
		if (load_in_ram(vm, &(champ[i]), rampos) == 84)
			return (84);
	}
	return (0);
}
