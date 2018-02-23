/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** test the get_as_int file
*/

/* File created the 13/02/2018 at 15:44:57 by julian.frabel@epitech.eu */

#include "my.h"
#include "corewar.h"
#include <criterion/criterion.h>

Test(get_indirect_as_int, return_is_expected, .timeout=10)
{
	byte_t indirect[IND_SIZE] = {0};

	indirect[IND_SIZE - 1] = 0;
	indirect[IND_SIZE - 2] = 1;
	cr_expect(get_indirect_as_int(indirect, 0) == 256);
	indirect[IND_SIZE - 1] = 6;
	indirect[IND_SIZE - 2] = 3;
	cr_expect(get_indirect_as_int(indirect, 0) == 774);
	cr_expect(get_indirect_as_int(NULL, 0) == 0);
}

Test(get_direct_as_int, return_is_expected, .timeout=10)
{
	byte_t direct[DIR_SIZE] = {0};

	direct[DIR_SIZE - 1] = 0x0;
	direct[DIR_SIZE - 2] = 0x1;
	cr_expect(get_direct_as_int(direct, 0) == 256);
	direct[DIR_SIZE - 1] = 0x6;
	direct[DIR_SIZE - 2] = 0x3;
	cr_expect(get_direct_as_int(direct, 0) == 774);
	direct[DIR_SIZE - 1] = 0x6;
	direct[DIR_SIZE - 2] = 0x3;
	direct[DIR_SIZE - 3] = 0x6;
	direct[DIR_SIZE - 4] = 0x3;
	cr_expect(get_direct_as_int(direct, 0) == 50725638);
	cr_expect(get_direct_as_int(NULL, 0) == 0);
}

Test(get_register_as_int, return_is_expected, .timeout=10)
{
	byte_t register_val[REG_SIZE] = {0};

	register_val[DIR_SIZE - 1] = 0x0;
	register_val[DIR_SIZE - 2] = 0x1;
	cr_expect(get_direct_as_int(register_val, 0) == 256);
	register_val[DIR_SIZE - 1] = 0x6;
	register_val[DIR_SIZE - 2] = 0x3;
	cr_expect(get_direct_as_int(register_val, 0) == 774);
	register_val[DIR_SIZE - 1] = 0x6;
	register_val[DIR_SIZE - 2] = 0x3;
	register_val[DIR_SIZE - 3] = 0x6;
	register_val[DIR_SIZE - 4] = 0x3;
	cr_expect(get_direct_as_int(register_val, 0) == 50725638);
	cr_expect(get_direct_as_int(NULL, 0) == 0);
}

Test(get_indirect_value_as_int, return_is_expected, .timeout=10)
{
	byte_t ram[5] = {0x01, 0x66, 0x72, 0xaa, 0xd0};

	cr_expect(get_indirect_value_as_int(1, ram, 0) == 1718790864);
}