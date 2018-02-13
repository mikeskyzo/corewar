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
			vm_functions/vm_ld.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

TESTS_DIR	=	$(realpath ./src)

TESTS_FILES	=	tests_get_as_int.c				\
			tests_create_vm.c				\
			tests_create_blank_champion.c			\
			tests_get_champion.c				\
			tests_vm_live.c

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