# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 23:43:42 by haryu             #+#    #+#              #
#    Updated: 2022/04/05 13:40:55 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME				= client.c cli_util.c
SRCNAME_BONUS		= client_bonus.c cli_util_bonus.c

OBJS 				= $(SRCNAME:.c=.o)
OBJS_BONUS			= $(SRCNAME_BONUS:.c=.o)

LIBFT				= libft
LIBFT_FLAGS			= -L ../ -lft

FT_PRINTF			= libftprintf
FT_PRINTF_FLAGS		= -L ../ -lftprintf

INC_FLAGS 			= -I ../includes/server/mandatory
INC_BONUS_FLAGS		= -I ../includes/server/bonus

NAME				= client
NAME_BONUS			= client_bonus
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
AR					= ar rcs
RM					= rm -f

sky					:=$(shell tput setaf 6)
reset				:=$(shell tput sgr0)

.c.o				:
					$(info $(sky)========== $(<) $(@) ==========$(reset))
					$(CC) $(CFLAGS) -c -o $@ $< $(INC_FLAGS) $(INC_BONUS_FLAGS)

$(NAME)				: $(OBJS)
					$(info $(sky)========== make Clent ==========$(reset))
					$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS)

$(NAME_BONUS)		: $(OBJS_BONUS)
					$(info $(sky)========== make Client_bonus ==========$(reset))
					$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS)

all					:$(NAME)
					$(info $(sky)<make> all$(reset))

clean				:
					$(info $(sky)========== clean ==========$(reset))
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean				: clean
					$(info $(sky)========== fclean ==========$(reset))
					$(RM) $(NAME) $(NAME_BONUS)

re					:fclean all
					$(info $(shell tput setaf 1)========== re ==========$(reset))

bonus				:$(NAME_BONUS)
					$(info $(sky)<make> bonus$(reset))

.PHONY				: all clean fclean re bonus
