/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Display an int on the screen
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	return (my_putnbr_base(nb, "0123456789"));
}

int	my_puterror_nbr(int nb)
{
	return (my_puterror_nbr_base(nb, "0123456789"));
}