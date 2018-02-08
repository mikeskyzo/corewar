/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Header for the asm
*/

#ifndef __ASM_H_
#define __ASM_H_

#include "op.h"
#include "mylist.h"

struct assembly_data_s {
	header_t header;
	linked_dict_t *labels;
};

typedef struct assembly_data_s assembly_data_t;

#endif