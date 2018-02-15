/*
** EPITECH PROJECT, 2017
** Corewar asm tests
** File description:
** Tests for args manager
*/

#include <criterion/criterion.h>
#include "my.h"
#include "asm.h"

Test(arg_manager, test_get_arg_type)
{
	cr_assert_eq(get_arg_type("%8"), T_DIR);
	cr_assert_eq(get_arg_type("8"), T_IND);
	cr_assert_eq(get_arg_type("r456"), T_REG);
	cr_assert_eq(get_arg_type("%:live"), T_DIR);
	cr_assert_eq(get_arg_type("test"), -1);
}

Test(arg_manager, test_caster)
{
	cr_assert_eq(caster(1, 42), 42);
	cr_assert_eq(caster(2, 42), 42);
	cr_assert_eq(caster(3, 42), 42);
	cr_assert_eq(caster(1, -42), 213);
	cr_assert_eq(caster(2, -42), 65493);
	cr_assert_eq(caster(3, -42), 4294967253);
	cr_assert_eq(caster(5, -5), -5);
}