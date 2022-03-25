# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 21:04:10 by haryu             #+#    #+#              #
#    Updated: 2022/03/25 20:02:52 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME			= coin.c element_call.c error_1.c error_2.c event_1.c event_2.c map_1.c map_2.c menu.c move.c player.c util.c main.c

SRCS_DIR = src/
SRCS_B_DIR = src_bonus/

OBJS			= ${addprefix ${SRCS_DIR}, ${SRCNAME:.c=.o}}
OBJS_BONUS		= ${addprefix ${SRCS_B_DIR}, ${SRCNAME:.c=.o}}

LIBFT			= libft
LIBFT_FLAGS		= -L library/libft -lft

SRC_GNL			= library/gnl/get_next_line.c\
				library/gnl/get_next_line_utils.c
OBJS_GNL		= ${SRC_GNL:.c=.o}

MLX				= mlx
MLX_FLAGS		= -L library/mlx -lmlx

INC_FLAGS		= -I inlcudes/mandatory/so_long\
				-I library/${LIBFT} -I library/gnl -I library/mlx/${mlx}

NAME			= so_long
CC				= gcc 
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

sky:=${shell tput setaf 6}
reset:=${shell tput sgr0}

all				: ${LIBFT} ${MLX} ${NAME}
				${info ${sky}<make> all${reset}}

debug			:${SRCS} ${SRC_GNL}
				${info ${sky}make debug - complete${reset}}
				${CC} ${CFLAGS} ${AR} ${ARFLAG} -g -fsanitze=address $^ -o ${NAME} ${LIBFT_FLAGS} ${MLX_FLAGS} ${INC_FLAGS}

${LIBFT}		:
				@make --silent --directory=library/${LIBFT}
				${info ${sky}1. make Libft - make complete$(reset)}

${MLX}			:
				@make --silent --directory=library/${MLX}
				${info ${sky}2. make MinilibX_mms - make complete$(reset)}

${NAME}			: ${OBJS} ${OBJS_GNL}
				${info ${sky}3. make so_long${reset}}
				${CC} ${CFLAGS} -o $@ $^ ${LIBFT_FLAGS} ${MLX_FLAGS}
				cp library/mlx/libmlx.dylib ${CURDIR}/

.c.o			:
				${info ${sky}========== $(<) $(@) ==========${reset}}
				${CC} ${CFLAGS} -c $< -o $@ $(INC_FLAGS)

clean			:
				${info ${sky}========== clean ==========${reset}}
				@make clean --directory=library/${LIBFT}
				${info ${sky}1. Libft : cleaned${reset}}
				@make clean --directory=library/${MLX}
				${info ${sky}2. MinilibX_mms : cleaned${reset}}
				${RM} ${OBJS} ${OBJS_GNL}

fclean			: clean
				${info ${sky}========== fclean ==========${reset}}
				make fclean --directory=library/${LIBFT}
				${info ${sky Libft - fcleaned ${reset}}}
				${RM} ${NAME}
				${RM} ${NAME}.dSYM

re: fclean all
	${info ${shell tput setaf 1}========== re ==========${reset}}

.PHONY: all clean fclean re bonus $(LIBFT) $(MLX) $(NAME)