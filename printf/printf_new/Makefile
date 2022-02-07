# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 22:02:23 by haryu             #+#    #+#              #
#    Updated: 2022/01/23 23:16:34 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_M		= ft_printf.c ft_printf_src.c ft_printf_src_hex.c

SRC_B		= 

DIR_M		= ./mandatory/
DIR_B		= ./bonus/

OBJ_M		= $(addprefix $(DIR_M), $(SRC_M:.c=.o))
OBJ_B		= $(addprefix $(DIR_B), $(SRC_B:.c=.o))

NAME		= libftprintf.a
cc			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm
RMFLAGS		= -f
AR			= ar
ARFLAGS		= rcs


.c.o		:
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)		:	$(OBJ_M)
			$(AR) $(ARFLAGS) $@ $^

all			: $(NAME)

clean		:
			$(RM) $(RMFLAGS) $(OBJ_M) $(OBJ_B)

fclean		: clean
			$(RM) $(RMFLAGS) $(NAME)

re			: fclean all

bonus		:
			$(AR) $(ARFLAGS) $(NAME) $(OBJ_B)

bonus_re	: fclean bonus

.PHONY		: all clean fclean re bonus bonus_re
