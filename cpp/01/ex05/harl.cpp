/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:24:55 by haryu             #+#    #+#             */
/*   Updated: 2022/09/24 10:39:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"


harl::harl(void) {
	funct[0].level = "debug";
	funct[0].funcPtr = &harl::debug;
	funct[1].level = "info"; 
	funct[1].funcPtr = &harl::info;
	funct[2].level = "warning";
	funct[2].funcPtr = &harl::warning;
	funct[3].level = "error"; 
	funct[3].funcPtr = &harl::error;
	funct[4].level = "wrong type";
	funct[4].funcPtr = &harl::wrongType;
}

void	harl::complain(std::string level) {
	int idx = 0;

	while (funct[idx].level.compare(level) != 0 && idx < 4)
		idx++;
	(this->*(funct[idx].funcPtr))();
	std::cout << " : " << level << std::endl;
	return ;
}

void	harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
}
void	harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
}
void	harl::warning(void) {
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
}
void	harl::error(void) {
	std::cout <<  "This is unacceptable! I want to speak to the manager now.";
}
void	harl::wrongType(void) {
	std::cout << "you typed wrong";
}