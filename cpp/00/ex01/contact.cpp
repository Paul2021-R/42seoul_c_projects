/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:38:12 by haryu             #+#    #+#             */
/*   Updated: 2022/09/09 16:24:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

ContactElement::ContactElement(int i) {
	int	IsEmpty = 0;
	int	index = i;
	first = last = nickname = number = secret = "          ";
	(void)IsEmpty;
	(void)index;
}

ContactElement::~ContactElement(){
	std::cout << "Contact [" << nickname << "] is deleted." << std::endl;
	IsEmpty = 0;
}

ContactElement::ContactElement(const ContactElement& ce) {
	first = ce.first;
	last = ce.last;
	nickname = ce.nickname;
	secret = ce.secret;
	IsEmpty = 1;
}

ContactElement& ContactElement::operator=(const ContactElement &ce) {
	first = ce.first;
	last = ce.last;
	nickname = ce.nickname;
	secret = ce.secret;
	IsEmpty = 1;
	return *this;
}

void	ContactElement::ShowContact(void) {
	std::cout << "==============" << std::endl;
	std::cout << "| " << "index  : " << index << " |" << std::endl;
	std::cout << "| " << first << " |" << std::endl;
	std::cout << "| " <<  last << " |" << std::endl;
	std::cout << "| " <<  nickname << " |" << std::endl;
	std::cout << "| " << number << " |" << std::endl;
	std::cout << "| " << secret << " |" << std::endl;
	std::cout << "==============" << std::endl;
	return ;
}

void	MakeTenString(std::string& temp, std::string& temp2){
	std::string	temp3;
	int			size;

	size = temp.length();
	temp3.resize(10);
	if (size > 10){
		temp.resize(9);
		temp.shrink_to_fit();
		temp.insert(9, temp2);
		}
	else {
		for (int i = 0; i < 10 - size; i++){
			temp3.insert(i, " ");
		}
		temp3 += temp;
		temp.swap(temp3);
	}
	temp3.clear();
	return ;
}

void	ContactElement::AddContact(void) {
	std::string temp;
	std::string temp2 = ".";

	std::cout << "Please put in First name." << std::endl;
	std::getline (std::cin, temp);
	MakeTenString(temp, temp2);
	first = temp;
	std::cout << "Please put in last name." << std::endl;
	std::getline (std::cin, temp);
	MakeTenString(temp, temp2);
	last = temp;
	std::cout << "Please put in nickname." << std::endl;
	std::getline (std::cin, temp);
	MakeTenString(temp, temp2);
	nickname = temp;
	std::cout << "Please put in Phone number." << std::endl;
	std::getline (std::cin, temp);
	MakeTenString(temp, temp2);
	number = temp;
	std::cout << "Please put in Secret Memo." << std::endl;
	std::getline (std::cin, temp);
	MakeTenString(temp, temp2);
	secret = temp;
	IsEmpty = 1;
}
