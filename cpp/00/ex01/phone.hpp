/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:43:28 by haryu             #+#    #+#             */
/*   Updated: 2022/09/09 17:09:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
# define PHONE_HPP

# include "contact.hpp"

class PhoneBook {
	ContactElement		Contacts[8];
	int					Indexed;
	public:
		PhoneBook();
		~PhoneBook();
		PhoneBook(const PhoneBook& Data);
		PhoneBook& operator=(const PhoneBook& Data);
		void	AddDatas();
		void	DeleteDatas();
		void	SearchDatas();
		void	ShowAll();
};

#endif
