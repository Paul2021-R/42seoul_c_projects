/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:41:29 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 14:14:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name) {
	WeaponB = NULL;
}

void	HumanB::attack(void) {
	std::string atr = ATTACK;
	std::cout << name << atr << WeaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& Weapon) {
	WeaponB = &Weapon;
}

const std::string HumanB::getName(void) {return name;}

Weapon& HumanB::getWeapon(void) {return *WeaponB;}