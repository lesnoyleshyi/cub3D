NAME	=	cub3D

SRC_DIR	=	./srcs/

LIBFT	=	./srcs/libft/libft.a

HEADER	=	$(addprefix ./includes, constants.h cub.h strings.h structs.h)

FILES	=	$(addprefix parser/, check_id.c check_valid_map.c convert_line_to_data.c	\
						convert_line_to_map.c create_data.c create_map.c get_index.c 	\
						get_subline.c parse.c put_error.c read_file.c up_atoi.c			\
						validation_check.c )

SRCS	=	main.c \
			$(addprefix ${SRC_DIR}, ${FILES})

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

.PHONY		:	re, clean, fclean, test, libft

%.o			:	%.c	${HEADER}
				${CC} ${CFLAGS} -c $< -o $@

all			:	${NAME}

${NAME}		:	${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}	:	libft ;

libft		:
				${MAKE} -C ./srcs/libft

clean		:
				rm -rf ${OBJS}
				${MAKE} -C ./srcs/libft clean

fclean		:	clean
				rm -rf ${NAME}
				${MAKE} -C ./srcs/libft fclean