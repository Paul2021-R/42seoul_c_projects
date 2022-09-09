/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:32:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/09 17:08:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"
#include "contact.hpp"

PhoneBook::ContactElement() PhoneBook::Contacts[] {
	for (int i = 0; i < 8; i ++)
	{
		Contacts[i](i);
	}
}
