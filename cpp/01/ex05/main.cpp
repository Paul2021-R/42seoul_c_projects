/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:12:14 by haryu             #+#    #+#             */
/*   Updated: 2022/09/24 10:48:42 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "harl.hpp"

int main(void) {
	harl		harl;
	std::string	Command;

	while (true) {
		std::cout << "Please type command to prompt/" << std::endl;
		std::cout << "(1) debug" << std::endl;
		std::cout << "(2) info" << std::endl;
		std::cout << "(3) warning"  << std::endl;
		std::cout << "(4) error" << std::endl;
		std::cout << "(5) exit" << std::endl;
		getline(std::cin, Command);
		if (std::cin.eof() && Command.size() == 0)
			return (1);
		if (Command.compare("exit") == 0)
			return (0);
		if (Command.size() == 0)
			continue ;
		harl.complain(Command);
	}
}