/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 03:21:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon):
	name(name),
	weaponA(Weapon) {}

HumanA::HumanA(HumanA &target) {
	name = target.name;
	weaponA.setType(target.weaponA.getType());
}

HumanA::~HumanA(void) {}

HumanA&	HumanA::operator=(HumanA &target) {
	name.clear();
	name = target.getName();
	Weapon temp;
	temp.setType(target.weaponA.getType());
	weaponA.setType(temp.getType());	
	return *this;
}

void	HumanA::attack(void) {
	std::string atr = ATTACK;
	std::cout << name << atr << std::endl;
}

const std::string HumanA::getName(void) {return name;}

const Weapon& HumanA::getWeapon(void) {
	return weaponA;
}