/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:43:28 by haryu             #+#    #+#             */
/*   Updated: 2022/09/13 01:35:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

# include "contact.hpp"

class PhoneBook {
	ContactElement		Contacts[8];
	public:
		PhoneBook() {};
		~PhoneBook() {
			std::cout << "Delete All Contacts." << std::endl;
		};
		PhoneBook(const PhoneBook& Data);
		PhoneBook& operator=(const PhoneBook& Data);
		void	AddDatas(int index);
		void	SearchDatas(std::string& target);
		void	ShowAll();
};

#endif
