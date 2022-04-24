# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 23:43:42 by haryu             #+#    #+#              #
#    Updated: 2022/04/24 16:46:12 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME				= main.c fill_stack.c errch_integer.c \
					  utils_linked_1.c utils_linked_2.c get_lis.c utils_array.c \
					  series_s.c series_p.c series_r.c series_rr.c \
					  check_best_choice.c lis_algorithm.c check_already_done.c \
					  get_score.c exception_lis.c exception_lis_2.c

SRCNAME_BONUS		= main_bonus.c fill_stack_bonus.c errch_integer_bonus.c \
					  utils_linked_1_bonus.c utils_linked_2_bonus.c \
					  series_s_bonus.c series_p_bonus.c series_r_bonus.c series_rr_bonus.c \
					  errch_commands_bonus.c check_already_done_bonus.c checker_core_bonus.c

DIR					= ./src/
DIR_BONUS			= ./src_bonus/

OBJS 				= $(addprefix $(DIR), $(SRCNAME:.c=.o))
OBJS_BONUS			= $(addprefix $(DIR_BONUS), $(SRCNAME_BONUS:.c=.o))

LIBFT				= libft
LIBFT_FLAGS			= -L ./ -lft

FT_PRINTF			= libftprintf
FT_PRINTF_FLAGS		= -L ./ -lftprintf

LIBFT_GNL			= libftgnl
LIBFT_GNL_FLAGS 	= -L ./ -lftgnl

LIBFT_DIR			= ./library/libft
FTPRINTF_DIR		= ./library/ft_printf
GNL_DIR				= ./library/get_next_line

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
					$(CC) $(CFLAGS) $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $@ -g -fsanitize=address

$(NAME_BONUS)		: $(OBJS_BONUS)
					$(info $(sky)============= libft.a =============$(reset))
					make -C $(LIBFT_DIR)
					@cp ./library/libft/libft.a ./
					$(info $(sky)========== libftpritnf.a ==========$(reset))
					make -C $(FTPRINTF_DIR)
					@cp ./library/ft_printf/libftprintf.a ./
					$(info $(sky)========== libftgnl.a ==========$(reset))
					@make -C $(GNL_DIR)
					cp ./library/get_next_line/libftgnl.a ./
					$(info $(sky)========== make push_swap_checker ==========$(reset))
					$(CC) $(CFLAGS) -o  $@ $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $(LIBFT_GNL_FLAGS) -g -fsanitize=address

.c.o				:
					$(info $(sky)========== $(<) $(@) ==========$(reset))
					$(CC) $(CFLAGS) $< -c -o $@ -g

clean				:
					$(info $(sky)============= clean libft.a =============$(reset))
					make clean -C $(LIBFT_DIR)
					$(info $(sky)========== clean libftpritnf.a ==========$(reset))
					make clean -C $(FTPRINTF_DIR)
					$(info $(sky)========== clean libftgnl.a ==========$(reset))
					@make clean -C $(GNL_DIR)
					$(info $(sky)========== clean ==========$(reset))
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean				: clean
					$(info $(sky)============= fclean libft.a =============$(reset))
					make fclean -C $(LIBFT_DIR)
					$(info $(sky)========== fclean libftpritnf.a ==========$(reset))
					make fclean -C $(FTPRINTF_DIR)
					$(info $(sky)========== fclean libftgnl.a ==========$(reset))
					@make fclean -C $(GNL_DIR)
					$(info $(sky)========== fclean ==========$(reset))
					$(RM) $(NAME) $(NAME_BONUS)
					@rm -rf libft.a
					@rm -rf libftprintf.a
					@rm -rf libftgnl.a

re					:fclean all
					$(info $(shell tput setaf 1)========== re ==========$(reset))

bonus				:$(NAME_BONUS)
					$(info $(sky)========== make bonus ===========$(reset))

.PHONY				: all clean fclean re bonus 
