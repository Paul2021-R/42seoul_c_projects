# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 23:43:42 by haryu             #+#    #+#              #
#    Updated: 2022/04/05 13:39:50 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME				= server.c ser_util.c
SRCNAME_BONUS		= server_bonus.c ser_util_bonus.c

OBJS 				= $(SRCNAME:.c=.o)
OBJS_BONUS			= $(SRCNAME_BONUS:.c=.o)

LIBFT				= libft
LIBFT_FLAGS			= -L ../ -lft

FT_PRINTF			= libftprintf
FT_PRINTF_FLAGS		= -L ../ -lftprintf

INC_FLAGS 			= -I ../includes/mandatory
INC_BONUS_FLAGS		= -I ../includes/bonus

NAME				= server
NAME_BONUS			= server_bonus
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= rm -f
AR					= ar -rcs

sky					:=$(shell tput setaf 6)
reset				:=$(shell tput sgr0)

all					:$(NAME)
					$(info $(sky)========== all ===========$(reset))

$(NAME)				: $(OBJS)
					$(info $(sky)========== make Server ==========$(reset))
					$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $^ -o $@

$(NAME_BONUS)		: $(OBJS_BONUS)
					$(info $(sky)========== make Server_bonus ==========$(reset))
					$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS)

.c.o				:
					$(info $(sky)========== $(<) $(@) ==========$(reset))
					$(CC) $(CFLAGS) $< -c -o $@ 

clean				:
					$(info $(sky)========== clean ==========$(reset))
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean				: clean
					$(info $(sky)========== fclean ==========$(reset))
					$(RM) $(NAME) $(NAME_BONUS)

re					:fclean all
					$(info $(shell tput setaf 1)========== re ==========$(reset))

bonus				:$(NAME_BONUS)
					$(info $(sky)========== make bonus ===========$(reset))

.PHONY				: all clean fclean re bonus 
