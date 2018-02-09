/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** op.c for the asm part
*/

#include <stdlib.h>
#include "op.h"
#include "writer.h"

op_t	op_tab[] = {
	{"live", 1, {T_DIR}, 1, 10, "alive"},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,\
"et (and  r1, r2, r3   r1&r2 -> r3"},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,\
"ou  (or   r1, r2, r3   r1 | r2 -> r3"},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,\
"ou (xor  r1, r2, r3   r1^r2 -> r3"},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,\
"load index"},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,\
"store index"},
	{"fork", 1, {T_DIR}, 12, 800, "fork"},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,\
"long load index"},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
	{"aff", 1, {T_REG}, 16, 2, "aff"},
	{0, 0, {0}, 0, 0, 0}
};

void run_op(int fd, char *line)
{
	char **parsed_line = my_str_to_word_array(line, " ");

	for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
		if (my_strcmp(parsed_line[0], op_tab[i].mnemonique) == 0) {
			run_specific_op(fd, op_tab[i], i, parsed_line);
		}
	}
}

void run_specific_op(int fd, op_t op, int index, char **parsed_line)
{
	char **args = my_str_to_word_array(parsed_line[1],\
my_char_to_str(SEPARATOR_CHAR));
	int size;

	write(fd, index, sizeof(char));
	for (int i = 0; args[i] != NULL; i++) {
		size = get_arg_size(args[i]);
		write(fd, get_arg_value(args[i]), size);
	}
}

short start_with(char *str, char *start)
{
	if (my_strlen(str) < my_strlen(start))
		return (0);
	for (int i = 0; start[i] != 0; i++)
		if (str[i] != start[i])
			return (0);
	return (1);
}