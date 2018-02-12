##
## EPITECH PROJECT, 2017
## Header makefile
## File description:
## makefile for libmy
##

CC	=	gcc

CFLAGS	+=	-I ./include -W -Wall -pedantic

SRC_DIR	=	src/

SRC	=	push.c \
		append.c \
		my_list_size.c \
		pop.c \
		dict_add.c \
		dict_fetch.c \
		dict_destroy.c \

OBJ	=	$(SRC:%.c=$(SRC_DIR)%.o)

NAME	=	libmylist.a

all: 	$(NAME)

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug:	CFLAGS += -O0 -s -g
debug:	re
