/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:40 by haryu             #+#    #+#             */
/*   Updated: 2022/09/08 20:03:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class ContactElement {
	private:
		std::string	first;
		std::string	last;
		std::string nickname;
		std::string	number;
		std::string	secret;
		int			IsEmpty;
		int			index;
	public:
		ContactElement(int i);
		~ContactElement();
		ContactElement(const ContactElement& ce);
		ContactElement& operator=(const ContactElement& ce);
		void ShowContact(void);
		void AddContact(void);
};

#endif
