/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** op.c for the asm part
*/

#include <stdlib.h>
#include "op.h"
#include <stdbool.h>
#include "corewar.h"

op_t	op_tab[] = {
	{"live", 1, {T_DIR}, 1, 10, false, false, "alive", vm_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, true, false, "load", vm_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, true, false, "store", vm_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, true, false, "addition", \
vm_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, true, false, "soustraction", \
vm_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,\
true, false, "et (and  r1, r2, r3   r1&r2 -> r3", vm_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,\
true, false, "ou  (or   r1, r2, r3   r1 | r2 -> r3", vm_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,\
true, false, "ou (xor  r1, r2, r3   r1^r2 -> r3", vm_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, false, true, "jump if zero", vm_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,\
true, true, "load index", vm_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,\
true, true, "store index", vm_sti},
	{"fork", 1, {T_DIR}, 12, 800, false, true, "fork", vm_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, true, true, "long load", \
vm_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,\
true, true, "long load index", vm_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, false, true, "long fork", vm_lfork},
	{"aff", 1, {T_REG}, 16, 2, true, false, "aff", vm_aff},
	{0, 0, {0}, 0, 0, false, false, 0, NULL}
};
