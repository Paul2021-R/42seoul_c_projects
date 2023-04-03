# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 22:02:23 by haryu             #+#    #+#              #
#    Updated: 2022/04/23 13:12:29 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_M		= get_next_line.c get_next_line_utils.c

OBJ_M		= $(SRC_M:.c=.o)

NAME		= libftgnl.a
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

.PHONY		: all clean fclean re bonus bonus_re
