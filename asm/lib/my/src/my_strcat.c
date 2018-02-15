/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

int my_strdupcat(char **dest, char *src)
{
	int dest_len = my_limit_strlen(*dest, '\0');
	int src_len = my_limit_strlen(src, '\0');
	char *new_str = malloc(sizeof(*new_str) * (dest_len + src_len + 1));
	int i = 0;
	int j = 0;

	if (new_str == NULL || dest == NULL || *dest == NULL || src == NULL)
		return (84);
	for (; i < dest_len; i++)
		new_str[i] = (*dest)[i];
	for (j = 0; j < src_len; j++)
		new_str[i + j] = src[j];
	new_str[i + j] = '\0';
	free(*dest);
	*dest = new_str;
	return (0);
}