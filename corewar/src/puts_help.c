/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** puts the help
*/

#include "my.h"

void puts_help()
{
	my_putstr("USAGE\n");
	my_putstr("\t./corewar [-dump nbr_cycle] [[-n prog_number]");
	my_putstr("[-a load_address] prog_name] ...\n\n");
	my_putstr("DESCRIPTION\n\t-dump nbr_cycle\tdumps the memory after");
	my_putstr("the nbr_cycle execution (if the round isn’t\n\t\t\t");
	my_putstr("already over) with the following format: 32 bytes/line in");
	my_putstr("\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n\t-n prog_number\t");
	my_putstr("sets the next program’s number. By default, the first ");
	my_putstr("free number\n\t\t\tin the parameter order\n\t");
	my_putstr("-a load_address\tsets the next program’s loading address");
	my_putstr(". When no address is\n\t\t\tspecified, optimize the ");
	my_putstr("addresses so that the processes are as far\n\t\t\taway ");
	my_putstr("from each other as possible. The addresses are MEM_SIZE");
	my_putstr(" modulo.\n");
}
