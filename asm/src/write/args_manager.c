/*
** EPITECH PROJECT, 2017
** Corewar asm
** File description:
** Arguments manager
*/

#include "my.h"
#include "asm.h"
#include "writer.h"

type_chars_size_t types_sizes[] = {
	{&is_register, T_REG},
	{&is_direct, T_DIR},
	{&is_indirect, T_IND},
	{&is_label_get, T_DIR},
	{NULL, 0}
};

int get_arg_type(char *arg)
{
	if (arg == NULL)
		return (-1);
	for (int i = 0; types_sizes[i].verif_func != NULL; i++) {
		if (types_sizes[i].verif_func(arg))
			return (types_sizes[i].size);
	}
	return (-1);
}

int get_arg_value(char *arg, int *pos, assembly_data_t *datas)
{
	int label_pos = 0;
	int index = 0;

	if (is_label_get(&arg[1])) {
		label_pos = *((int *)dict_fetch(datas->labels, &arg[2]));
		if (label_pos == -1) {
			my_puterror("Cannot find label !\n");
			return (0);
		}
		return ((unsigned short)(label_pos - *pos));
	}
	if (arg[0] < '0' || arg[0] > '9')
		index = 1;
	return (my_getnbr(&arg[index]));
}