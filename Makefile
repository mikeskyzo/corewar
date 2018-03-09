##
## EPITECH PROJECT, 2017
## CPE_corewar_2017
## File description:
## Run both Makefile
##

all:
		$(MAKE) -C asm/
		$(MAKE) -C corewar/

clean:
		$(MAKE) clean -C asm/
		$(MAKE) clean -C corewar/

fclean:
		$(MAKE) fclean -C asm/
		$(MAKE) fclean -C corewar/

tests_run:
		$(MAKE) -C asm/tests
		$(MAKE) -C corewar/tests
		./asm/tests/test
		./corewar/tests/test

re:		fclean all