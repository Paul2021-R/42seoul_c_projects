# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 23:43:42 by haryu             #+#    #+#              #
#    Updated: 2022/04/17 22:08:33 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME				= main.c fill_stack.c errch_integer.c utils_forbidden.c utils_linked_1.c utils_linked_2.c get_lis.c utils_array.c series_s.c series_p.c series_r.c series_rr.c

SRCNAME_BONUS		= 

DIR					= ./src/

OBJS 				= $(addprefix $(DIR), $(SRCNAME:.c=.o))
OBJS_BONUS			= $(addprefix $(DIR), $(SRCNAME_BONUS:.c=.o))

GNL_DIR				= ./library/ 
GNL_SRC				= get_next_line.c get_next_line_utils.c
GNL 				= $(addprefix $(GNL_DIR), $(GNL_SRC:.c=.o))

LIBFT				= libft
LIBFT_FLAGS			= -L ./ -lft

FT_PRINTF			= libftprintf
FT_PRINTF_FLAGS		= -L ./ -lftprintf

LIBFT_DIR			= ./library/libft
FTPRINTF_DIR		= ./library/ft_printf

INC_FLAGS 			= -I ./includes
INC_BONUS_FLAGS		= -I ./includes

NAME				= push_swap
NAME_BONUS			= checker
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra

sky					:=$(shell tput setaf 6)
reset				:=$(shell tput sgr0)

all					:$(NAME)
					$(info $(sky)=============== all ===============$(reset))


$(NAME)				: $(OBJS)
					$(info $(sky)============= libft.a =============$(reset))
					make -C $(LIBFT_DIR)
					@cp ./library/libft/libft.a ./
					$(info $(sky)========== libftpritnf.a ==========$(reset))
					make -C $(FTPRINTF_DIR)
					@cp ./library/ft_printf/libftprintf.a ./
					$(info $(sky)========== make push_swap ==========$(reset))
					$(CC) $(CFLAGS) $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $@ -O -g -fsanitize=address

$(NAME_BONUS)		: $(OBJS_BONUS)
					$(info $(sky)========== make Server_bonus ==========$(reset))
					$(CC) $(CFLAGS) -o  $@ $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS)

.c.o				:
					$(info $(sky)========== $(<) $(@) ==========$(reset))
					$(CC) $(CFLAGS) $< -c -o $@ -g -O1

clean				:
					$(info $(sky)============= clean libft.a =============$(reset))
					make clean -C $(LIBFT_DIR)
					$(info $(sky)========== clean libftpritnf.a ==========$(reset))
					make clean -C $(FTPRINTF_DIR)
					$(info $(sky)========== clean ==========$(reset))
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean				: clean
					$(info $(sky)============= fclean libft.a =============$(reset))
					make fclean -C $(LIBFT_DIR)
					$(info $(sky)========== fclean libftpritnf.a ==========$(reset))
					make fclean -C $(FTPRINTF_DIR)
					$(info $(sky)========== fclean ==========$(reset))
					$(RM) $(NAME) $(NAME_BONUS)
					@rm -rf libft.a
					@rm -rf libftprintf.a

re					:fclean all
					$(info $(shell tput setaf 1)========== re ==========$(reset))

bonus				:$(NAME_BONUS)
					$(info $(sky)========== make bonus ===========$(reset))

.PHONY				: all clean fclean re bonus 
