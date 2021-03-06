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
#define ERR_EMPTY_FILE "empty file."
#define ERR_NAME_REDEFINED "name can only be defined once."
#define ERR_COMMENT_REDEFINED "comment can only be defined once."
#define ERR_TOO_LONG_NAME "program name is too long."
#define ERR_TOO_LONG_COMMENT "comment is too long."
#define ERR_NO_NAME_DEFINED "no name specified."
#define ERR_MULTIPLE_LABEL_DEFINITION "multiple definitions of the label."
#define ERR_UNKNOWN_LABEL "unknown label."
#define ERR_SYNTAX "syntax error."
#define WARNING_NO_COMMENT_DEFINED "asm : warning : no comment specified.\n"

#define ERROR_MSG_SIZE 128

struct assembly_data_s {
	header_t header;
	linked_dict_t *labels;
	linked_list_t *label_gets;
	char error_msg[ERROR_MSG_SIZE];
	int error_line;
};

typedef struct assembly_data_s assembly_data_t;

struct label_get_s {
	char *name;
	int line;
};

typedef struct label_get_s label_get_t;

void clean_str(char **str);
void clean_word_array(char ***word_array);

int is_header_info(char *instruction);
int process_header_info(char *instruction, assembly_data_t *data);

int is_file_valid(int fd, assembly_data_t *data);
int parse_label_and_return_instruction_size(char *instruction, \
assembly_data_t *data, int instruction_line);
int verify_instruction(char *instruction, assembly_data_t *data);
int are_label_get_valid(assembly_data_t *data);
void write_error_message(assembly_data_t *data);

op_t *get_op_by_mnemonic(char *mnemonique);

int is_register(char *param);
int is_direct(char *param);
int is_indirect(char *param);
int is_label_set(char *param);
int is_label_get(char *param);
int get_type_size(int type, op_t *op);

#endif