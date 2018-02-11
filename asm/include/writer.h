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

int get_arg_value(char *arg);
void run_op(int fd, char *line);
void run_specific_op(int fd, op_t op, int index, char **parsed_line);
short start_with(char *str, char *start);
void writer(int fd, int read_fd, assembly_data_t *datas);
int get_arg_type(char *arg);
int get_big_endians(int val);

#endif