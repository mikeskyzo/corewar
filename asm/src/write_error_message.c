/*
** EPITECH PROJECT, 2017
** PSU_corewar_2017
** File description:
** Write an error message on the error output
*/

/* File created the 09/03/2018 at 16:46:14 by julian.frabel@epitech.eu */

#include "my.h"
#include "asm.h"

void write_error_message(assembly_data_t *data)
{
	my_puterror("asm: error : ");
	if (data->error_line) {
		my_puterror("line ");
		my_puterror_nbr(data->error_line);
		my_puterror(" : ");
	}
	my_puterror(data->error_msg);
	my_puterror("\n");
}