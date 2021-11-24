# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 00:30:34 by haryu             #+#    #+#              #
#    Updated: 2021/11/24 19:17:34 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME			= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
				ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
				ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
				ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCNAME_B		= ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c

OBJS			= ${SRCNAME:.c=.o}
OBJS_BONUS		= ${SRCNAME_B:.c=.o}

NAME			= libft.a
CC				= gcc
RM				= rm -f
LIB				= ar rcs
CFLAGS			= -Wall -Wextra -Werror

ifdef BONUS_PART
	OBJ_SWITCH = ${OBJS_BONUS}
else
	OBJ_SWITCH = ${OBJS}
endif

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJ_SWITCH}
		${LIB} $@ $^

all		:	bonus ${NAME}

clean	:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean	:	clean
		${RM} ${NAME}

re		:	fclean all

bonus	:
		$(MAKE) BONUS_PART=1 $(NAME)

.PHONY	:	all clean fclean re bonus
