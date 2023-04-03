/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:32:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/13 01:54:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"
#include "contact.hpp"

void	PhoneBook::AddDatas(int index) {
	Contacts[index].AddContact();
}

void	PhoneBook::SearchDatas(std::string& target){
	int	find = -1;

	for (int i = 0; i < 8; i++)
	{
		if (Contacts[i].FindContact(target) == true) {
			find = i;
			std::cout << find << std::endl;
			Contacts[find].ShowContact();
		}
	}
	if (find < 0)
		std::cout << " [ " << target << " ] " << "can't find." << std::endl;
}

void	PhoneBook::ShowAll(void) {
	for (int i = 0; i < 8; i++){
		if (Contacts[i].GetEmpty() == false)
			Contacts[i].ShowContact();
	}
}
