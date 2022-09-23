/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 14:11:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon):
	name(name),
	WeaponA(Weapon) {}

void	HumanA::attack(void) {
	std::string atr = ATTACK;
	std::cout << name << atr << getWeapon().getType() << std::endl;
}

const std::string HumanA::getName(void) {return name;}

Weapon& HumanA::getWeapon(void) {return WeaponA;}