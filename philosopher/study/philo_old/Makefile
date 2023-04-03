# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:10:23 by haryu             #+#    #+#              #
#    Updated: 2022/07/07 13:01:57 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME				= $(wildcard ./*.c)

OBJS 				= $(SRCNAME:.c=.o)

NAME				= philo
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -g -fsanitize=address
RM					= rm -f

sky					:=$(shell tput setaf 6)
reset				:=$(shell tput sgr0)

.c.o				:
					$(info $(sky)========== $(<) $(@) ==========$(reset))
					$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME)				: $(OBJS)
					$(info $(sky)========== make $(NAME) ==========$(reset))
					$(CC) $(CFLAGS) -o $@ $^

all					:$(NAME)
					$(info $(sky)<make> all$(reset))

clean				:
					$(info $(sky)========== clean ==========$(reset))
					$(RM) $(OBJS)

fclean				: clean
					$(info $(sky)========== fclean ==========$(reset))
					$(RM) $(NAME) $(OBJS)

re					:fclean all
					$(info $(shell tput setaf 1)========== re ==========$(reset))

.PHONY				: all clean fclean re bonus
