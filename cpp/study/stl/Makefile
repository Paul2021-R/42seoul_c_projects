CC				= g++
CFLAG			= -std=c++98
SRC_DIR			= ./
SRCS			= $(wildcard $(SRC_DIR)*.cpp)
OBJS			= $(SRCS:.cpp=.o)
NAME			= $(SRCS:.cpp=.out)

all				:$(NAME)
	make clean

$(NAME)			:$(OBJS)
	$(CC) $(CFLAG) $< -o $@

$(OBJS)			:%.o:%.cpp
	$(CC) $(CFLAG) -c $< -o $(subst .cpp,.o,$@)

clean			:
	rm -rf *.o

fclean			: clean
	rm -rf *.out

re				: clean all

.PHONY			: all clean re
