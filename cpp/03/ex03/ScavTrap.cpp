/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 02:32:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : 
	ClapTrap("default", 100, 50, 20),
	hitPoint(ClapTrap::hitPoint)
 {
	type.clear();
	type.assign("ScavTrap");
    std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}
ScavTrap::ScavTrap(const std::string& name) : 
	ClapTrap(name, 100, 50, 20),
	hitPoint(ClapTrap::hitPoint) {
    type.clear();
	type.assign("ScavTrap");
    std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}

ScavTrap::ScavTrap(const std::string& name, Point_i hp, Point_i ep, Point_i ad) : 
	ClapTrap(name, hp, ep, ad),
	hitPoint(ClapTrap::hitPoint) {
	type.clear();
	type.assign("ScavTrap");
    std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}

ScavTrap::ScavTrap(const ScavTrap& target) : 
    ClapTrap(target.name),
	hitPoint(ClapTrap::hitPoint) {
	type = target.type;
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy constructor operated" << std::endl;
    printConstructor(type);
}
ScavTrap& ScavTrap::operator=(const ScavTrap& target) {
    name.clear();
    name.assign(target.name);
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy Assign operator operated" << std::endl;
    printConstructor(type);
    return *this;
}
ScavTrap::~ScavTrap(void) {
	std::cout << type << " \" " << name << " \" is destroyed" << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << PURPLE << "<<< " << type << "'s Guard Gate Mode >>>" << std::endl;
    printConstructor(type);
}