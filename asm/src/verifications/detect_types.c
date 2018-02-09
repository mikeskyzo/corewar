/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Return if a param is from the specified type
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int is_register(char *param)
{
	int len = my_strlen(param);
	int number = 0;

	if (len < 2)
		return (0);
	number = my_getnbr(&param[1]);
	if (param[0] != 'r')
		return (0);
	if (number >= 1 && number <= REG_NUMBER && my_str_isnum(&param[1]))
		return (T_REG);
	return (0);
}

int is_direct(char *param)
{
	int len = my_strlen(param);

	if (len < 2)
		return (0);
	if (param[0] != DIRECT_CHAR)
		return (0);
	if (my_str_isnum(&param[1]) || is_label_get(&param[1]))
		return (T_DIR);
	return (0);
}

int is_indirect(char *param)
{
	if (param == NULL)
		return (0);
	if (my_str_isnum(param) || is_label_get(param))
		return (T_IND);
	return (0);
}

int is_label_set(char *param)
{
	if (param == NULL)
		return (0);
	for (int i = 0; param[i]; i++) {
		if (my_str_contains(param[i], LABEL_CHARS) != -1)
			continue;
		if (param[i] == LABEL_CHAR && param[i + 1] == '\0')
			return (T_LAB);
		break;
	}
	return (0);
}

int is_label_get(char *param)
{
	int i = 0;

	if (param == NULL || param[0] != LABEL_CHAR)
		return (0);
	for (i = 1; param[i]; i++) {
		if (my_str_contains(param[i], LABEL_CHARS) != -1)
			continue;
		break;
	}
	if (param[i] == '\0')
		return (T_LAB);
	return (0);
}