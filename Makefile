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

re:		fclean all