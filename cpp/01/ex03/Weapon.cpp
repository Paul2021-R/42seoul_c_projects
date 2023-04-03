/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:28:12 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 14:06:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const char *str) {
	type.assign(str);
}

const std::string& Weapon::getType(void) {
	const std::string &copy = type;
	return copy;
}

void Weapon::setType(std::string newWeapon) {
	type.clear();
	type.assign(newWeapon); // string class 기능 활용
}
