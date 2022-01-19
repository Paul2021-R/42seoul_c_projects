# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 16:31:46 by haryu             #+#    #+#              #
#    Updated: 2022/01/19 13:24:27 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME0			= ft_printf.c
SRCNAME1			= ft_calloc.c ft_itoa.c ft_putstr.c ft_strdup.c ft_strlen.c\
					  ft_toupper.c ft_bzero.c ft_memmove.c
SRCNAME2			= ft_chartostr.c ft_itoa_16.c ft_uitoa.c ft_ltostr_16.c\
					  switch_integer.c switch_integer_16.c ft_strrev.c

SRC_DIR0			= ./
SRC_DIR1			= ./LIBFT/
SRC_DIR2			= ./SRC/

OBJS_0				= $(addprefix $(SRC_DIR0), $(SRCNAME0:.c=.o))
OBJS_1				= $(addprefix $(SRC_DIR1), $(SRCNAME1:.c=.o))
OBJS_2				= $(addprefix $(SRC_DIR2), $(SRCNAME2:.c=.o))

INCULDE				= ./ft_printf.h

NAME				= libftprintf.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= rm -f
AR					= ar
ARFLAGS				= '-rcs'

.c.o:
					$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):			$(OBJS_0) $(OBJS_1) $(OBJS_2)
					$(AR) $(ARGLAGS) $@ $^

all:				$(NAME)

clean:
					$(RM) $(OBJS_0) $(OBJS_1) $(OBJS_2)

fclean:				clean
					$(RM) $(NAME

re:					fclean all

.PHONY:				all cleaan fclean re
