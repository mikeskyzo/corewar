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
	{"live", 1, {T_DIR}, 1, 10, false, false, "alive"},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, true, false, "load"},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, true, false, "store"},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, true, false, "addition"},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, true, false, "soustraction"},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,\
true, false, "et (and  r1, r2, r3   r1&r2 -> r3"},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,\
true, false, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,\
true, false, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
	{"zjmp", 1, {T_DIR}, 9, 20, false, true, "jump if zero"},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,\
true, true, "load index"},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,\
true, true, "store index"},
	{"fork", 1, {T_DIR}, 12, 800, false, true, "fork"},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, true, true, "long load"},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,\
true, true, "long load index"},
	{"lfork", 1, {T_DIR}, 15, 1000, false, true, "long fork"},
	{"aff", 1, {T_REG}, 16, 2, true, false, "aff"},
	{0, 0, {0}, 0, 0, false, false, 0}
};