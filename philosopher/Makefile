#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:10:10 by haryu             #+#    #+#              #
#    Updated: 2022/04/30 15:34:26 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo
NAME_BONUS		= philo_bonus

DIR				= ./src/
DIR_BONUS		= ./src_bonus/

sky				:=$(shell tput setaf 6)
reset			:=$(shell tput sgr0)

all				:
				$(info $(shell tput setaf 1)============= philo =============$(reset))
				make -C $(DIR)
				@cp ./src/philo ./philo

bonus			:
				$(info $(shell tput setaf 1)============= philo_bonus =============$(reset))
				make -C $(DIR_BONUS)
				@cp ./src_bonus/philo_bonus ./philo_bonus

clean			:
				$(info $(sky)============= philo ==============$(reset))
				make clean -C $(DIR)
				$(info $(sky)============= philo_bonus ==============$(reset))
				make clean -C $(DIR_BONUS)
				$(info $(shell tput setaf 1)============= cleaning completed =============$(reset))

fclean			:
				$(info $(shell tput setaf 1)============= $(NAME) fclean =============$(reset))
				make fclean -C $(DIR)
				$(info $(shell tput setaf 1)============= $(NAME_BONUS) fclean =============$(reset))
				make fclean -C $(DIR_BONUS)
				@rm -rf philo philo_bonus

re				: fclean all
				$(info $(shell tput setaf 1)============= make re =============$(reset))

.PHONY			: all bonus clean fclean re 
