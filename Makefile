NAME		=	cub3D

SRC_DIR		=	./srcs/

LIBFT		=	./srcs/libft/libft.a

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

HEADER		=	$(addprefix includes/, constants.h cub.h strings.h structs.h)

FILES		=	$(addprefix parser/, check_id.c check_valid_map.c convert_line_to_data.c	\
						convert_line_to_map.c create_data.c create_map.c get_index.c 		\
						get_subline.c parse.c put_error.c read_file.c up_atoi.c				\
						validation_check.c)													\
				$(addprefix mlx_utils/, init_mlx.c)											\
				$(addprefix game/, init_game.c exit.c execute_action.c)

SRCS		=	$(addprefix ${SRC_DIR}, xlam.c main.c ${FILES})

OBJS		=	${SRCS:.c=.o}

.PHONY		:	re clean fclean test libft

all			:	${NAME}

${NAME}		:	${LIBFT} ${OBJS}
				${CC} ${CFLAGS} -L ./srcs/mlx -l mlx -framework OpenGL -framework AppKit ${OBJS} ${LIBFT} -o ${NAME}

%.o			:	%.c ${HEADER}
				${CC} ${CFLAGS} -c $< -o $@

${LIBFT}	:	libft ;

libft		:
				${MAKE} -C ./srcs/libft

clean		:
				rm -rf ${OBJS}
				${MAKE} -C ./srcs/libft clean

fclean		:	clean
				rm -rf ${NAME}
				${MAKE} -C ./srcs/libft fclean

re			:	fclean all