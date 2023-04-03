NAME				= CPP Module 07

sky					= $(shell tput setaf 6)
alret				= $(shell tput setaf 1)
green				= $(shell tput setaf 2)
reset				= $(shell tput sgr0)


all					: 
					$(info $(alret)====================  Make $(NAME)  ====================$(reset))
					make -C ./ex00/
					make -C ./ex01/
					make -C ./ex02/

clean				:
					$(info $(alret)====================  clean $(NAME)  ====================$(reset))
					make clean -C ./ex00/
					make clean -C ./ex01/
					make clean -C ./ex02/
					
fclean				: 
					$(info $(alret)====================  fclean $(NAME)  ====================$(reset))
					make fclean -C ./ex00/
					make fclean -C ./ex01/
					make fclean -C ./ex02/

debug				:
					$(info $(alret)====================  Debug $(NAME)  ====================$(reset))
					make debug -C ./ex00/
					make debug -C ./ex01/
					make debug -C ./ex02/

re					: fclean all
					$(info $(green)====================  remake $(NAME)  ====================$(reset))

.PHONY				: all clean fclean re
