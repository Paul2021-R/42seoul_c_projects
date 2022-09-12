/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:30:02 by haryu             #+#    #+#             */
/*   Updated: 2022/09/13 01:27:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phone.hpp"
//#include "phone.hpp"

/*
int main(void){
	ContactElement cur[9];
	int				j;

	for (int i = 0; i < 9; i++) cur[i].ShowContact();

	for (int i = 0; i < 11; i++)
	{
		if (i > 8) j = i - 9;
		else j = i;
		cur[j].AddContact();
		cur[j].ShowContact();
		std::cout << "전체 할당 연락처 수 : " << ContactElement::ShowTotal() << "/8"  << std::endl;
	}
	return (0);
}*/

int	main(void){
	std::string	target;
	int			index = 0;
	PhoneBook	book;

	while (true) {
		std::cout << "Please, type command or number.\n(0) All\n(1) ADD\n(2) SEARCH\n(3) EXIT\n" << std::endl;
		std::getline(std::cin, target);
		if (!target.compare("ALL") || !target.compare("0")){
			std::cout << "You choose 0" << std::endl << std::endl;
			book.ShowAll();
		}
		else if (!target.compare("ADD") || !target.compare("1")){
			std::cout << "You choose 1" << std::endl;
			book.AddDatas(index);
			index++;
		}
		else if (!target.compare("SEARCH") || !target.compare("2")) {
			std::cout << "You choose 2" << std::endl;
			std::cout << "Please type to find contacts(first, last, nickname ... etc)" << std::endl;
			std::getline(std::cin, target);
			book.SearchDatas(target);
		}
		else if (!target.compare("EXIT") || !target.compare("3")) {
			std::cout << "Terminate Phone Book" << std::endl;
			break ;
		}
		else {
			std::cout << "Please Your command is wrong. : " << target << std::endl;
		}
		std::cout << "================================================" << std::endl;
		if (index == 8) index = 0;
	}
	return (0);
}
