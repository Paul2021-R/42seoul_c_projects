/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:24:55 by haryu             #+#    #+#             */
/*   Updated: 2022/09/24 10:58:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"


harl::harl(void) {
	funct[0].level = "DEBUG";
	funct[0].funcPtr = &harl::debug;
	funct[1].level = "INFO"; 
	funct[1].funcPtr = &harl::info;
	funct[2].level = "WARNING";
	funct[2].funcPtr = &harl::warning;
	funct[3].level = "ERROR"; 
	funct[3].funcPtr = &harl::error;
	funct[4].level = "wrong type";
	funct[4].funcPtr = &harl::wrongType;
}

void	harl::complain(std::string level) {
	int idx = 0;

	while (funct[idx].level.compare(level) != 0 && idx < 4)
		idx++;
	switch(idx) {
		case 0:
			(this->*(funct[0].funcPtr))();
			break ;
		case 1:
			(this->*(funct[1].funcPtr))();
			break ;
		case 2:
			(this->*(funct[2].funcPtr))();
			break ;
		case 3:
			(this->*(funct[3].funcPtr))();
			break ;
		default:
			(this->*(funct[4].funcPtr))();
	}
	return ;
}

void	harl::debug(void) {
	std::cout << "[ " << funct[0].level << " ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	harl::info(void) {
	std::cout << "[ " << funct[1].level << " ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	harl::warning(void) {
	std::cout << "[ " << funct[2].level << " ]" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	harl::error(void) {
	std::cout << "[ " << funct[3].level << " ]" << std::endl;
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void	harl::wrongType(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}