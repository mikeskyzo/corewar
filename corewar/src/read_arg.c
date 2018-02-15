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
	if (option < 0 || option > MEM_SIZE) {
		puts_help();
		exit(84);
	}
	return (option);
}

champ_t *loop_read(char **av, int *i, champ_t *champ_tab)
{
	int dump;
	static int n = 0;
	static int load = 0;
	static int nb_prog = 0;

	if (my_strcmp("-dump", av[*i]) != 0)
		if (my_strcmp("-n", av[*i]) == 0)
			nb_prog = check_option(av, &*i);
		else if (my_strcmp("-a", av[*i]) == 0)
			load = check_option(av, &*i);
		else {
			champ_tab[n] = get_champ(av[*i], load, nb_prog);
			load = 0;
			nb_prog = 0;
			n++;
		}
	else
		dump = check_option(av, &*i);
	return (champ_tab);
}

champ_t *read_arg(char **av)
{
	champ_t *champ_tab;

	champ_tab = malloc(sizeof(champ_t) * 2);
	if (champ_tab == NULL) {
		my_puterror("Fail to malloc\n");
		exit(84);
	}
	for (int i = 1; av[i]; i++)
		champ_tab = loop_read(av, &i, champ_tab);
	return (champ_tab);
}
