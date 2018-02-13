##
## EPITECH PROJECT, 2017
## CPE_corewar_2017
## File description:
## Compile the corewar part
##

FUNC_DIR	=	$(realpath src/vm_functions)

FUNC_FILES	=	live.c

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c						\
			op.c						\
			create_vm.c					\
			get_champion.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES)) $(addprefix $(FUNC_DIR)/, $(FUNC_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	corewar

INCLUDE		=	-I include -I lib/my/include -I lib/mylist/include

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy \
			-L $(LIB_DIR)mylist -lmylist

LIB		=	$(LIB_DIR)my/libmy.a

CC		=	gcc

all:		$(NAME)

$(NAME):	$(LIB) $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

$(LIB):
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) -C $(LIB_DIR)mylist
		$(MAKE) clean -C $(LIB_DIR)my
		$(MAKE) clean -C $(LIB_DIR)mylist

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re