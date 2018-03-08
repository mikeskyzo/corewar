/*
** EPITECH PROJECT, 2017
** Pool
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static short is_delim(char c, char *delimiter);

int count_word(char const *str, char *delim)
{
	int counter = 0;

	if (str == NULL || delim == NULL || my_strlen(str) <= 0)
		return (0);
	for (int i = 0; str[i + 1] != 0; i++) {
		if (is_delim(str[i], delim) && !is_delim(str[i + 1], delim)) {
			counter++;
		}
	}
	return (counter);
}

int get_next_word_size(char const *str, int index, char *delim)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[index] == '"') {
		for (i = index + 1; str[i] != 0 && str[i] != '"'; i++);
		return (i + 1);
	}
	for (i = index; str[i] != 0 && !is_delim(str[i], delim); i++);
	return (i);
}

char *get_next_word(char const *str, int index, char *delim)
{
	int i;
	char *res = malloc(get_next_word_size(str, index, delim) + 1);

	if (str == NULL || delim == NULL)
		return (NULL);
	if (str[index] == '"') {
		res[0] = str[index];
		for (i = index + 1; str[i] != 0 && str[i] != '"'; i++)
			res[i - index] = str[i];
		res[i - index] = str[i];
		res[i - index + 1] = 0;
		return (res);
	}
	for (i = index; str[i] != 0 && !is_delim(str[i], delim); i++) {
		res[i - index] = str[i];
	}
	res[i] = 0;
	return (res);
}

char **my_str_to_word_array(char const *str, char *delim)
{
	int counter = 0;
	int i = 0;
	char **arr;

	arr = malloc((count_word(str, delim) + 2) * sizeof(char *));
	if (my_strlen(str) <= 0 || arr == NULL || delim == NULL) {
		free(arr);
		return (NULL);
	}
	if (!is_delim(str[0], delim)) {
		arr[counter++] = get_next_word(str, 0, delim);
		i++;
	}
	for (; str[i] != 0; i++) {
		if (is_delim(str[i], delim) && !is_delim(str[i + 1], delim)) {
			arr[counter++] = get_next_word(&str[i + 1], 0, delim);
			i += my_strlen(arr[counter - 1]);
		}
	}
	arr[counter] = NULL;
	return (arr);
}

short is_delim(char c, char *delimiter)
{
	if (c == 0)
		return (1);
	for (int i = 0; delimiter[i] != 0; i++)
		if (delimiter[i] == c)
			return (1);
	return (0);
}