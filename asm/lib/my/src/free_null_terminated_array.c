/*
** EPITECH PROJECT, 2017
** my
** File description:
** Free a null terminated array
*/

#include "my.h"

int free_null_terminated_word_array(void **array)
{
	if (array == NULL)
		return (84);
	for (int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
	return (0);
}

int array_size(void **array)
{
	int size = 0;

	if (array == NULL)
		return (0);
	for (int size = 0; array[size]; size++);
	return (size);
}