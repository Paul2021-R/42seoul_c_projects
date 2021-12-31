# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 16:31:46 by haryu             #+#    #+#              #
#    Updated: 2021/12/31 16:58:49 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME				= ft_printf.c

SRC_DIR				= ./
SRC_DIR2			= ./SRC/

OBJS				= $(addprefix $(SRC_DIR), $(SRCNAME):.c=.o)


INCULDE				= ./INCLUDE/libft.h

NAME				= libftprintf.a
NAME_tmp			= testout.out
CC					= gcc
CFLAGS				= -Wall -Wextra - Werror
RM					= rm -f
AR					= ar
ARFLAGS				= rcs

.c.o:
					$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

$(NAME):			$(OBJS)
					$(AR) $(ARGLAGS) $@ $^

all:				$(NAME)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all cleaan fclean re
