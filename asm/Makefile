##
## EPITECH PROJECT, 2017
## CPE_corewar_2017
## File description:
## Compile the asm part
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c \
			op.c \

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	asm

INCLUDE		=	-I include \
			-I lib/my/include \
			-I lib/mylist/include \

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy \
			-L $(LIB_DIR)mylist -lmylist \

LIB		=	$(LIB_DIR)my/libmy.a

LIBLIST		=	$(LIB_DIR)mylist/libmylist.a

CC		=	gcc

all:		$(NAME)

$(NAME):	$(LIB) $(LIBLIST) $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

$(LIB):
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) clean -C $(LIB_DIR)my

$(LIBLIST):
		$(MAKE) -C $(LIB_DIR)mylist
		$(MAKE) clean -C $(LIB_DIR)mylist

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re