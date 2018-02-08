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

void clean_str(char **str);

int verify_instruction(char *instruction);

int size_of_type_byte(op_t *mnemonic);
op_t *get_op_by_mnemonic(char *mnemonique);

int is_register(char *param);
int is_direct(char *param);
int is_indirect(char *param);
int is_label_set(char *param);
int is_label_get(char *param);

#endif