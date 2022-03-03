NAME	=	cub3D

SRCS	=	main.c \
			$(addprefix $SRC_DIR, something)

SRC_DIR	=	./srcs

OBJS	=	$(addprefix ${SRC_DIR}/,${SRCS:.c=.o})

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

.PHONY	:	re, clean, fclean, test

test	:
			${OBJS}