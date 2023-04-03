/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 01:30:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : 
	ClapTrap("default"),
    name(ClapTrap::getName()),
    type("ScavTrap"),
	hitPoint(ClapTrap::getHp()),
    energyPoint(50),
    attackDamage(20) {
    hitPoint = 100;
    std::cout << type << " : Default Constructor operated." << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
ScavTrap::ScavTrap(const std::string& name) : 
    ClapTrap(name),
    name(name),
    type("ScavTrap"),
	hitPoint(ClapTrap::getHp()),
    energyPoint(50),
    attackDamage(20) {
    hitPoint = 100;
    std::cout << type << " : Default Constructor operated." << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
ScavTrap::ScavTrap(const ScavTrap& target) : 
    ClapTrap(target.name),
    name(target.name),
    type("ScavTrap"),
	hitPoint(target.hitPoint),
    energyPoint(target.energyPoint),
    attackDamage(target.attackDamage) {
    std::cout << type << " : Copy constructor operated" << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
ScavTrap& ScavTrap::operator=(const ScavTrap& target) {
    name.clear();
    name.assign(target.name);
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy Assign operator operated" << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return *this;
}
ScavTrap::~ScavTrap(void) {
	std::cout << type << " \" " << name << " \" is destroyed" << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << PURPLE << "<<< " << type << "'s Guard Gate Mode >>>" << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}

void        ScavTrap::attack(const std::string& target) {
    ClapTrap::attack(target, getName(), getType(), getHp(), getEp(), getAd());
}
void        ScavTrap::takeDamage(Point_i amount) {
    ClapTrap::takeDamage(amount, getName(), getType(), getHp());
}
void        ScavTrap::beRepaired(Point_i amount) {
    ClapTrap::beRepaired(amount, getName(), getType(), getHp(), getEp());
}

bool        ScavTrap::initHitPoint(Point_i amount) {
    bool    ret;
    
    ret = ClapTrap::initHitPoint(amount, getName(), getType(), getHp());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool        ScavTrap::initEnergyPoint(Point_i amount) {
    bool    ret;

    ret = ClapTrap::initEnergyPoint(amount, getName(), getType(), getEp());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool        ScavTrap::initAttackDamage(Point_i amount) {
    bool    ret;

    ret = ClapTrap::initAttackDamage(amount, getName(), getType(), getAd());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool        ScavTrap::setName(std::string target) {
    bool    ret;

    ret = ClapTrap::setName(target, getName(), getType());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}