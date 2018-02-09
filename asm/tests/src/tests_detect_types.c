/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** Test the detect_type functions
*/

/* File created the 09/02/2018 at 18:05:45 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "my.h"
#include "asm.h"

Test(is_register, test_the_is_register_function)
{
	cr_expect(is_register("r1"));
	cr_expect(is_register("r16"));
	cr_expect(is_register("r7"));
	cr_expect(!is_register("r0"));
	cr_expect(!is_register("r17"));
	cr_expect(!is_register("r1a"));
	cr_expect(!is_register("R1"));
	cr_expect(!is_register("ra"));
	cr_expect(!is_register(""));
	cr_expect(!is_register("A"));
	cr_expect(!is_register("1r"));
	cr_expect(!is_register(NULL));
}

Test(is_direct, test_the_is_direct_function)
{
	cr_expect(is_direct("%1"));
	cr_expect(is_direct("%16"));
	cr_expect(is_direct("%:label"));
	cr_expect(is_direct("%-1"));
	cr_expect(!is_direct("r0"));
	cr_expect(!is_direct("aer"));
	cr_expect(!is_direct("1"));
	cr_expect(!is_direct("%notlabel:"));
	cr_expect(!is_direct(""));
	cr_expect(!is_direct("A"));
	cr_expect(!is_direct("1r"));
	cr_expect(!is_direct(NULL));
}

Test(is_indirect, test_the_is_indirect_function)
{
	cr_expect(is_indirect("1"));
	cr_expect(is_indirect("18"));
	cr_expect(is_indirect(":label"));
	cr_expect(is_indirect("-1"));
	cr_expect(!is_indirect(""));
	cr_expect(!is_indirect("%5"));
	cr_expect(!is_indirect("notalabel:"));
	cr_expect(!is_indirect("A"));
	cr_expect(!is_indirect("r1"));
	cr_expect(!is_indirect(NULL));
}

Test(is_label_set, test_if_str_is_a_label_set)
{
	cr_expect(is_label_set("label:"));
	cr_expect(is_label_set("live:"));
	cr_expect(is_label_set("04j_z:"));
	cr_expect(!is_label_set(""));
	cr_expect(!is_label_set("lAbel:"));
	cr_expect(!is_label_set("r1"));
	cr_expect(!is_label_set(":label"));
	cr_expect(!is_label_set(NULL));
}