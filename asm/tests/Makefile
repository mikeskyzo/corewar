##
## EPITECH PROJECT, 2017
## CPE_corewar_2017
## File description:
## Unit test makefile for the asm part
##

SRC_DIR		=	$(realpath ../src)

SRC_FILES	=	verifications/detect_types.c			\
			verifications/parse_labels_and_verify_instruction.c \
			verifications/verify_file.c			\
			verifications/header_info.c			\
			verifications/verify_label_get.c		\
			verifications/verify_instruction.c		\
			write/args_manager.c				\
			write/op_manager.c				\
			write/writer.c					\
			write/get_op.c					\
			write/label_set_manager.c			\
			clean_str.c					\
			get_op_by_mnemonic.c				\
			op.c						\
			write_error_message.c


SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

TESTS_DIR	=	$(realpath ./src)

TESTS_FILES	=	tests_detect_types.c				\
			tests_is_comment.c

SRC_TESTS	=	$(addprefix $(TESTS_DIR)/, $(TESTS_FILES))

OBJ		=	$(SRC:%.c=%.o) $(SRC_TESTS:%.c=%.o)

CCTMP		=	$(SRC:%.c=%.gcno) $(SRC:%.c=%.gcda) $(SRC_TESTS:%.c=%.gcno) $(SRC_TESTS:%.c=%.gcda)

NAME		=	test

INCLUDE		=	-I ../include					\
			-I ../lib/my/include				\
			-I ../lib/mylist/include

CFLAGS		=	-Wall -Wextra -coverage
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	../lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy 				\
			-L $(LIB_DIR)mylist -lmylist			\
			-lcriterion -lgcov

CC		=	gcc

all:		$(NAME)

$(NAME):	libs
		$(CC) -o $(NAME) $(SRC) $(SRC_TESTS) $(LIB_FLAGS) $(CFLAGS)

libs:
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) -C $(LIB_DIR)mylist

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