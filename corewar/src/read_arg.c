/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** read the arg and return the champ tab
*/

#include "corewar.h"
#include "my.h"
#include <stdlib.h>

int check_option(char **av, int *i)
{
	int option;

	i[0]++;
	if (!av[*i]) {
		puts_help();
		exit(84);
	}
	if (my_str_isnum(av[*i]) == 0) {
		puts_help();
		exit(84);
	}
	option = my_getnbr(av[*i]);
	if (option < 0) {
		puts_help();
		exit(84);
	}
	return (option);
}

int get_nb_prog(champ_t *champ_tab, int nb_champ, int nb_prog)
{
	int nb = 1;

	if (nb_prog != -1)
		return (nb_prog);
	for (int i = 0; i < nb_champ; i++) {
		if (champ_tab[i].nb_prog != i + 1)
			break;
		nb++;
	}
	return (nb);
}

int loop_read(char **av, int *i, champ_t *champ_tab, int *nb_champ)
{
	static int dump = 0;
	static int n = 0;
	static int load = -1;
	static int nb_prog = -1;

	if (my_strcmp("-dump", av[*i]) != 0)
		if (my_strcmp("-n", av[*i]) == 0)
			nb_prog = check_option(av, &*i);
		else if (my_strcmp("-a", av[*i]) == 0)
			load = check_option(av, &*i);
		else {
			nb_prog = get_nb_prog(champ_tab, *nb_champ, nb_prog);
			champ_tab[n] = get_champ(av[*i], load, nb_prog);
			nb_champ[0]++;
			load = -1;
			nb_prog = -1;
			n++;
		}
	else
		dump = check_option(av, i);
	return (dump);
}

champ_t *read_arg(char **av, int ac, int *nb_champ, int *dump)
{
	champ_t *champ_tab;

	if (ac < 2) {
		puts_help();
		exit(84);
	}
	if (my_strcmp(av[1], "-h") == 0 || my_strcmp(av[1], "--help") == 0) {
		puts_help();
		exit(0);
	}
	champ_tab = malloc(sizeof(champ_t) * 4);
	if (champ_tab == NULL) {
		my_puterror("Fail to malloc\n");
		exit(84);
	}
	for (int i = 1; av[i]; i++)
		*dump = loop_read(av, &i, champ_tab, nb_champ);
	return (champ_tab);
}
