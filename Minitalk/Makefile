# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 00:11:11 by haryu             #+#    #+#              #
#    Updated: 2022/04/30 15:29:08 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= Minitalk
LIBFT_DIR				= ./library/libft
FTPRINTF_DIR			= ./library/ft_printf
CLI_DIR					= ./src_client/
SER_DIR					= ./src_server/

sky					:=$(shell tput setaf 6)
reset				:=$(shell tput sgr0)

all				:
				$(info $(sky)============= libft.a =============$(reset))
				make -C $(LIBFT_DIR)
				@cp ./library/libft/libft.a ./
				$(info $(sky)========== libftpritnf.a ==========$(reset))
				make -C $(FTPRINTF_DIR)
				@cp ./library/ft_printf/libftprintf.a ./
				$(info $(sky)============= server ==============$(reset))
				make -C $(CLI_DIR)
				$(info $(sky)============= client ==============$(reset))
				make -C $(SER_DIR)
				$(info $(shell tput setaf 1)============= $(NAME) =============$(reset))
				@cp ./src_client/client ./
				@cp ./src_server/server ./

bonus			:
				$(info $(sky)============= libft.a =============$(reset))
				make -C $(LIBFT_DIR)
				$(info $(sky)========== libftpritnf.a ==========$(reset))
				make -C $(FTPRINTF_DIR)
				$(info $(sky)========== server_bonus ===========$(reset))
				make bonus -C $(CLI_DIR)
				$(info $(sky)========== client_bonus ===========$(reset))
				make bonus -C $(SER_DIR)
				$(info $(shell tput setaf 1)============= $(NAME) bonus part =============$(reset))
				@cp ./library/libft/libft.a ./
				@cp ./library/ft_printf/libftprintf.a ./
				@cp ./src_client/client_bonus ./
				@cp ./src_server/server_bonus ./

clean			:
				$(info $(sky)============= clean libft.a =============$(reset))
				make clean -C $(LIBFT_DIR)
				$(info $(sky)========== clean libftpritnf.a ==========$(reset))
				make clean -C $(FTPRINTF_DIR)
				$(info $(sky)============= clean server ==============$(reset))
				make clean -C $(CLI_DIR)
				$(info $(sky)============= clean client ==============$(reset))
				make clean -C $(SER_DIR)
				$(info $(shell tput setaf 1)============= $(NAME) clean =============$(reset))

fclean			:
				$(info $(sky)============= fclean libft.a =============$(reset))
				make fclean -C $(LIBFT_DIR)
				$(info $(sky)========== fclean libftpritnf.a ==========$(reset))
				make fclean -C $(FTPRINTF_DIR)
				$(info $(sky)============= fclean server ==============$(reset))
				make fclean bonus -C $(CLI_DIR)
				$(info $(sky)============= fclean client ==============$(reset))
				make fclean -C $(SER_DIR)
				$(info $(shell tput setaf 1)============= $(NAME) fclean =============$(reset))
				@rm -rf libft.a
				@rm -rf libftprintf.a
				@rm -rf client server client_bonus server_bonus

re				: fclean all
				$(info $(shell tput setaf 1)============= $(NAME) recompile =============$(reset))

.PHONY			: all bonus clean fclean re 