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

int get_arg_type_size(char *arg)
{
	if (arg == NULL)
		return (-1);
	for (int i = 0; types_sizes[i].verif_func != NULL; i++) {
		if (types_sizes[i].verif_func(arg))
			return (types_sizes[i].size);
	}
	return (-1);
}

int get_arg_value(char *arg)
{
	return (my_getnbr(arg));
}