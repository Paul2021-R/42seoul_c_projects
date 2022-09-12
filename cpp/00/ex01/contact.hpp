/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:40 by haryu             #+#    #+#             */
/*   Updated: 2022/09/13 01:29:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class ContactElement {
	private:
		static int	TotalIndexedNum;
		static int	pos;
		std::string	first;
		std::string	last;
		std::string nickname;
		std::string	number;
		std::string	secret;
		bool		IsEmpty;
		int			index;
	public:
		ContactElement();
		~ContactElement();
		ContactElement(const ContactElement& ce);
		ContactElement& operator=(const ContactElement& ce);
		void	ShowContact(void);
		void	AddContact(void);
		bool	GetEmpty(void) {return IsEmpty;};
		bool	FindContact(std::string& target);
		static int		ShowTotal(void) {return TotalIndexedNum;}
};

#endif
