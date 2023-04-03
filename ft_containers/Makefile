NAME				= ft_container

CC					= c++
CFLAG				= -Wall -Wextra -Werror -std=c++98
AR					= ar
ARFLAG				= rcs

SRCS_DIR			= ./
SRCS				= $(wildcard $(SRCS_DIR)*.cpp)
OBJS				= $(SRCS:.cpp = .o)
sky					= $(shell tput setaf 6)
alret				= $(shell tput setaf 1)
green				= $(shell tput setaf 2)
reset				= $(shell tput sgr0)


.cpp.o:
					$(CC) $(CFLAG) -c -o $@ $<

all					: $(NAME)

$(NAME)				: $(OBJS)
					$(info $(sky)====================  $(NAME)  ====================$(reset))
					$(CC) $(CFLAG) -o $(NAME) $(OBJS)
					$(CC) $(CFLAG) -D STDMODE=1 -o std_container $(OBJS)

clean				:
					$(info $(alret)====================  clean $(NAME)  ====================$(reset))
					rm -rf $(SRCS_DIR)*.o

fclean				: 
					$(info $(alret)====================  fclean $(NAME)  ====================$(reset))
					rm -rf $(NAME)
					rm -rf std_container
					rm -rf $(SRCS_DIR)*.o
					rm -rf $(NAME).dSYM
					rm -rf std_container.dSYM


debug				:
					$(info $(alret)====================  Debug $(NAME)  ====================$(reset))
					$(CC) $(CFLAG) -g3 -D DG=1 -o $(NAME) $(OBJS)
					$(CC) $(CFLAG) -D STDMODE=1 -D DG=1 -o std_container $(OBJS)

re					: fclean all
					$(info $(green)====================  remake $(NAME)  ====================$(reset))
.PHONY				: all clean fclean re
