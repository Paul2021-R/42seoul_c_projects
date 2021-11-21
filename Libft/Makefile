# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 00:30:34 by haryu             #+#    #+#              #
#    Updated: 2021/11/22 00:57:40 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME			= 	ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_putchar_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\
#SRCNAME_BONUS	= 

SRCS			= ${SRCNAME}
#SRCS_BOUNS		= ${SRCNAME_BONUS}

OBJS			= ${SRCS:.c=.o}
#OBJS_BONUS		= ${SRCS:.c=.o}

NAME			= libft.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

ifdef WITH_BONUS
		OBJ_SWITCH = $(OBJS_BONUS)
else
		OBJ_SWITCH = $(OBJS)
endif

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJ_SWITCH}
				ar rc ${NAME} ${OBJ_SWITCH}

all:			bonus ${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

bonus:			
				$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY:		all clean fclean re bonus
