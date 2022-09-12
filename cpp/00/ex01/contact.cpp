/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:38:12 by haryu             #+#    #+#             */
/*   Updated: 2022/09/13 01:51:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int ContactElement::TotalIndexedNum = 0;
int ContactElement::pos = 0;

ContactElement::ContactElement(): IsEmpty(false), index(pos) {
	if (TotalIndexedNum < 8) {
		TotalIndexedNum++;
		pos++;
	}
}

ContactElement::~ContactElement(){
	//std::cout << "Contact '" << nickname << "' is deleted." << std::endl;
	IsEmpty = true;
	TotalIndexedNum--;
}

ContactElement::ContactElement(const ContactElement& ce) {
	first = ce.first;
	last = ce.last;
	nickname = ce.nickname;
	secret = ce.secret;
	IsEmpty = false;
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
	std::cout << "| " << "index  : " << index + 1 << " |" << std::endl;
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
	IsEmpty = false;
}

bool	ContactElement::FindContact(std::string &target) {
	std::string temp;
	std::string temp2 = ".";

	temp = target;
	MakeTenString(temp, temp2);
	if (!first.compare(temp))
		return (true);
	if (!last.compare(temp))
		return (true);
	if (!nickname.compare(temp))
		return (true);
	if (!number.compare(temp))
		return (true);
	if (!secret.compare(temp))
		return (true);
	return (false);
}
