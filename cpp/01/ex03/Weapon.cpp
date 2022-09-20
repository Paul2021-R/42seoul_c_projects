/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:28:12 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 02:35:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void) {
	const std::string &copy = type;
	return copy;
}

void Weapon::setType(std::string newWeapon) {
	type.clear();
	type.assign(newWeapon);
}
