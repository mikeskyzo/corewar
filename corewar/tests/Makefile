##
## EPITECH PROJECT, 2017
## CPE_corewar
## File description:
## Build the test binary
##

SRC_DIR		=	$(realpath ../src)

SRC_FILES	=	get_as_int.c					\
			op.c						\
			get_champion.c					\
			create_vm.c					\
			create_blank_champion.c				\
			vm_functions/vm_live.c				\
			vm_functions/vm_ld.c				\
			vm_functions/vm_st.c				\
			vm_functions/vm_add.c				\
			vm_functions/vm_sub.c				\
			vm_functions/vm_and.c				\
			vm_functions/vm_or.c				\
			vm_functions/vm_xor.c				\
			vm_functions/vm_zjump.c				\
			vm_functions/vm_ldi.c				\
			vm_functions/vm_sti.c				\
			vm_functions/vm_fork.c				\
			vm_functions/vm_lld.c				\
			vm_functions/vm_lldi.c				\
			vm_functions/vm_lfork.c				\
			vm_functions/vm_aff.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

TESTS_DIR	=	$(realpath ./src)

TESTS_FILES	=	tests_get_as_int.c				\
			tests_create_vm.c				\
			tests_create_blank_champion.c			\
			tests_get_champion.c				\
			tests_vm_live.c					\
			tests_vm_ld.c					\
			tests_vm_st.c					\
			tests_vm_add.c					\
			tests_vm_sub.c					\
			tests_vm_and.c					\
			tests_vm_or.c					\
			tests_vm_xor.c

SRC_TESTS	=	$(addprefix $(TESTS_DIR)/, $(TESTS_FILES))

OBJ		=	$(SRC:%.c=%.o) $(SRC_TESTS:%.c=%.o)

CCTMP		=	$(SRC:%.c=%.gcno) $(SRC:%.c=%.gcda) $(SRC_TESTS:%.c=%.gcno) $(SRC_TESTS:%.c=%.gcda)

NAME		=	test

INCLUDE		=	-I ../include -I ../lib/my/include -I ../lib/mylist/include

CFLAGS		=	-Wall -Wextra -coverage
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	../lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy -L $(LIB_DIR)mylist -lmylist -lcriterion -lgcov

LIB		=	$(LIB_DIR)my/libmy.a

CC		=	gcc

all:		$(NAME)

$(NAME):	$(LIB)
		$(CC) -o $(NAME) $(SRC) $(SRC_TESTS) $(LIB_FLAGS) $(CFLAGS)

$(LIB):
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) -C $(LIB_DIR)mylist
		$(MAKE) clean -C $(LIB_DIR)my
		$(MAKE) clean -C $(LIB_DIR)mylist

cclean:
		$(RM) $(CCTMP)
		$(RM) *.gcno
		$(RM) *.gcda
		$(RM) *.gcov

clean:		cclean
		$(RM) $(OBJ)

fclean:		clean
		$(RM) -f $(NAME)

re:		fclean all