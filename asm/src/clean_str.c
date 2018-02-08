/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Clean an str and return aa new pointer
*/

#include "my.h"

void clean_str(char **str)
{
	int len = my_strlen(*str);
	char **word_array = my_str_to_word_array(*str, " \t");
	char *new_str = malloc(sizeof(*new_str) * (len + 1));
	int pos_in_new_str = 0;

	if (word_array == NULL || new_str == NULL)
		return;
	for (int i = 0; i <= len; i++)
		new_str[i] = '\0';
	for (int i = 0; word_array[i]; i++) {
		for (int j = 0; word_array[i][j]; j++) {
			new_str[pos_in_new_str] = word_array[i][j];
			pos_in_new_str++;
		}
		new_str[pos_in_new_str] = ' ';
		pos_in_new_str++;
	}
	free_null_terminated_word_array(word_array);
	free(*str);
	*str = new_str;
}