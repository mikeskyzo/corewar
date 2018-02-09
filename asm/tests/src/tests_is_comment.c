/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** test if the line is a comment
*/

/* File created the 09/02/2018 at 18:32:45 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "my.h"
#include "asm.h"

Test(is_comment, test_the_is_comment_function)
{
	cr_expect(is_comment("# a comment"));
	cr_expect(is_comment("#		a$ c#oMment\n"));
	cr_expect(!is_comment("a #comment"));
	cr_expect(!is_comment(""));
	cr_expect(!is_comment(NULL));
}