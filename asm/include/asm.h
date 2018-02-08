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

#define ERR_OP_NOT_FOUND "unknown instruction."
#define ERR_INVALID_NB_ARG "invalid number of arguments."
#define ERR_INVALID_ARG_TYPE "invalid type of argument."

#define ERROR_MSG_SIZE 128

struct assembly_data_s {
	header_t header;
	linked_dict_t *labels;
	char error_msg[ERROR_MSG_SIZE];
};

typedef struct assembly_data_s assembly_data_t;

void clean_str(char **str);

int is_file_valid(int fd, assembly_data_t *data);
int verify_instruction(char *instruction, assembly_data_t *data);

int size_of_type_byte(op_t *mnemonic);
op_t *get_op_by_mnemonic(char *mnemonique);

int is_register(char *param);
int is_direct(char *param);
int is_indirect(char *param);
int is_label_set(char *param);
int is_label_get(char *param);

#endif