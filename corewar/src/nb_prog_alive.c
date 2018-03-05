/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** number of prog alive in the ram
*/

#include "corewar.h"
#include "mylist.h"
#include <stdlib.h>
#include "my.h"

int get_nbr_prog(champ_t *champ)
{
	if (champ->alive == true)
		return (champ->nb_prog);
	else
		return (-1);
}

int *put_in_list(int *live, int nb)
{
	for (int i = 0; live[i] != -1; i++) {
		if (live[i] == nb)
			break;
		if (live[i] == 0) {
			live[i] = nb;
			break;
		}
	}
	return (live);
}

int get_nbr_alive(int *live)
{
	int i = 0;

	while (live[i] != 0 && live[i] != -1)
		i++;
	return (i);
}

int *init_live(void)
{
	int *live;

	live = malloc(sizeof(int) * 5);
	if (live == NULL) {
		my_puterror("Fail to malloc\n");
		exit(84);
	}
	live[0] = 0;
	live[1] = 0;
	live[2] = 0;
	live[3] = 0;
	live[4] = -1;
	return (live);
}

int nb_prog_alive(vm_t *vm)
{
	int nb;
	int i;
	int *live;
	linked_list_t *cur = vm->programs;

	live = init_live();
	while (cur != NULL) {
		nb = get_nbr_prog(cur->data);
		if (nb != -1)
			live = put_in_list(live, nb);
		cur = cur->next;
	}
	i = get_nbr_alive(live);
	free(live);
	return (i);
}
