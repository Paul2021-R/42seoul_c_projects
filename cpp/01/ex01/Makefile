NAME				= ex01

CC					= g++
CFLAG				= -Wall -Wextra -Werror -std=c++98

SRCS_DIR			= ./
SRCS				= $(wildcard $(SRCS_DIR)*.cpp)
OBJS				= $(SRCS:.cpp = .o)
sky					= $(shell tput setaf 6)
alret				= $(shell tput setaf 1)
green				= $(shell tput setaf 2)
reset				= $(shell tput sgr0)


all					: $(NAME)

$(NAME)				: $(OBJS)
					$(info $(sky)====================  $(NAME)  ====================$(reset))
					$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean				:
					$(info $(alret)====================  clean $(NAME)  ====================$(reset))
					rm -rf $(SRCS_DIR)*.o

fclean				: 
					$(info $(alret)====================  fclean $(NAME)  ====================$(reset))
					rm -rf $(NAME)
					rm -rf $(SRCS_DIR)*.o

re					: fclean all
					$(info $(green)====================  remake $(NAME)  ====================$(reset))
.PHONY				: all clean fclean re
