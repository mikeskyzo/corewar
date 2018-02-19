/*
** EPITECH PROJECT, 2017
** corewar asm
** File description:
** writer header file
*/

#ifndef _ASM_WRITER_
#define _ASM_WRITER_

#include "asm.h"

typedef struct {
	args_type_t type;
	int value;
} arg_datas_t;

typedef struct {
	int (*verif_func)(char *params);
	int size;
} type_chars_size_t;

short start_with(char *str, char *start);
void writer(char *file_name, int read_fd, assembly_data_t *datas);
int get_arg_type(char *arg);
int get_big_endians(int val, int size);
int get_op_index(op_t op);
void run_op(int fd, char *line, int *pos, assembly_data_t *datas);
int run_specific_op(int fd, int *pos, char **parsed_line,\
assembly_data_t *datas);
op_t get_op(char *mnemonique);
int get_op_index(op_t op);
void label_set_manager(char ***parsed_line, char *line);
unsigned int get_arg_value(char *arg, int *pos, assembly_data_t *datas,\
int size);

#endif