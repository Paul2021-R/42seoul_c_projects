# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_make.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 23:21:13 by haryu             #+#    #+#              #
#    Updated: 2022/04/06 00:07:22 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

get_underbar()
{
	i=0
	limit=`tput cols`
	while [ $i -lt $limit ]
	do
		echo "=" | tr -d "\n"
		i=$(($i + 1))
	done
}

SavedDIR=$PWD
get_underbar
tput setaf 6; 
tput bold;
echo "Minitalk"
tput sgr0;
echo "Made by Haryu"
get_underbar

sleep 1 && clear

get_underbar
tput setaf 6; 
tput bold;
echo "norminette check"
tput sgr0;
echo "
"
norminette ./src_server ./src_client ./includes ./library
get_underbar && sleep 4 && clear

get_underbar
echo "make libft.a"
make -C ./library/libft
cp ./library/libft/libft.a $SavedDIR/
echo "Compilation of libft.a is finished."
get_underbar && sleep 2 && clear

get_underbar
echo "make libftprintf.a"
make -C ./library/ft_printf
cp ./library/ft_printf/libftprintf.a $SavedDIR/
echo "Compilation of libftprintf.a is finished."
get_underbar && sleep 2 && clear

get_underbar
echo "make Server"
make -C ./src_server
cp ./src_server/server $SavedDIR/
echo "Compilation of server is finished."
get_underbar && sleep 2 && clear

get_underbar
echo "make Server_bonus"
make bonus -C ./src_server
cp ./src_server/server_bonus $SavedDIR/
echo "Compilation of server_bonus is finished."
get_underbar && sleep 2 && clear

get_underbar
echo "make Client"
make -C ./src_client
cp ./src_client/client $SavedDIR/
echo "Compilation of client is finished."
get_underbar && sleep 2 && clear

get_underbar
echo "make Client_bonus"
make bonus -C ./src_client
cp ./src_client/client_bonus $SavedDIR/
echo "Compilation of client is finished."
get_underbar && sleep 2 && clear

get_underbar
echo "Compilation is finished."
echo "Please check Server and Client"
get_underbar && sleep 2 && clear