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
	return (tot_size / champ_nb);
}

static int compute_rampos(champ_t *champ_tab, int champ_ind, int champ_nb)
{
	int spacement = compute_spacement(champ_tab, champ_nb);
	int rampos = 0;

	for (int i = 0; i < champ_ind; i++)
		rampos += spacement + champ_tab[i].header.prog_size;
	return (rampos);
}

static void load_in_ram(vm_t *vm, champ_t *champ, int ram_pos)
{
	for (int i = 0; i < champ->header.prog_size; i++)
		vm->ram[(ram_pos + i) % MEM_SIZE] = champ->prog[i];
}

int load_champ(vm_t *vm, champ_t *champ, int champ_ind, int champ_nb)
{
	for (int i = 0; i < champ_nb; i++)
		load_in_ram(vm, &(champ[i]), \
compute_rampos(champ, i, champ_nb));
	return (NULL);
}

int load_champ_at(vm_t *vm, champ_t *champ, int champ_ind, int champ_nb)
{
	for (int i = 0; i < champ_nb; i++)
		load_in_ram(vm, &(champ[i]), \
compute_rampos(champ, i, champ_nb));
	return (NULL);
}