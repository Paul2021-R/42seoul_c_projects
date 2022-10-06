/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 02:32:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : 
	ClapTrap("default", 100, 100, 30),
	hitPoint(ClapTrap::hitPoint)
 {
	type.clear();
	type.assign("FragTrap");
    std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}
FragTrap::FragTrap(const std::string& name) : 
	ClapTrap(name, 100, 100, 30),
	hitPoint(ClapTrap::hitPoint) {
    type.clear();
	type.assign("FragTrap");
    std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}
FragTrap::FragTrap(const std::string name, Point_i hp, Point_i ep, Point_i ad) :
	ClapTrap(name, hp, ep, ad),
	hitPoint(ClapTrap::hitPoint) {
	type.clear();
	type.assign("FragTrap");
    std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}
FragTrap::FragTrap(const FragTrap& target) : 
    ClapTrap(target.name),
	hitPoint(ClapTrap::hitPoint) {
	type = target.type;
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy constructor operated" << std::endl;
    printConstructor(type);
}
FragTrap& FragTrap::operator=(const FragTrap& target) {
    name.clear();
    name.assign(target.name);
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy Assign operator operated" << std::endl;
    printConstructor(type);
    return *this;
}
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap \" " << name << " \" is destroyed" << std::endl;
}

void    FragTrap::highFiveGuys(void) {
	std::cout << type << " \" " << name << " \" wanna high five with you!" << std::endl;
}