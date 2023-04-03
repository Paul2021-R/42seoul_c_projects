/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 01:37:42 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : 
	ClapTrap("default"),
    name(ClapTrap::getName()),
    type("FragTrap"),
	hitPoint(ClapTrap::getHp()),
    energyPoint(100),
    attackDamage(30) {
    hitPoint = 100;
    std::cout << type << " : Default Constructor operated." << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
FragTrap::FragTrap(const std::string& name) : 
    ClapTrap(name),
    name(name),
    type("FragTrap"),
	hitPoint(ClapTrap::getHp()),
    energyPoint(100),
    attackDamage(30) {
    hitPoint = 100;
    std::cout << type << " : Default Constructor operated." << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
FragTrap::FragTrap(const FragTrap& target) : 
    ClapTrap(target.name),
    name(target.name),
    type("FragTrap"),
	hitPoint(target.hitPoint),
    energyPoint(target.energyPoint),
    attackDamage(target.attackDamage) {
    std::cout << type << " : Copy constructor operated" << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
FragTrap& FragTrap::operator=(const FragTrap& target) {
    name.clear();
    name.assign(target.name);
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy Assign operator operated" << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return *this;
}
FragTrap::~FragTrap(void) {
	std::cout << type << " \" " << name << " \" is destroyed" << std::endl;
}

void    FragTrap::highFiveGuys(void) {
    std::cout << type << " \" " << name << " \" wanna make a high five" << std::endl;
}

void    FragTrap::attack(const std::string& target) {
    ClapTrap::attack(target, getName(), getType(), getHp(), getEp(), getAd());
}
void    FragTrap::takeDamage(Point_i amount) {
    ClapTrap::takeDamage(amount, getName(), getType(), getHp());
}
void    FragTrap::beRepaired(Point_i amount) {
    ClapTrap::beRepaired(amount, getName(), getType(), getHp(), getEp());
}

bool    FragTrap::initHitPoint(Point_i amount) {
    bool    ret;
    
    ret = ClapTrap::initHitPoint(amount, getName(), getType(), getHp());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool    FragTrap::initEnergyPoint(Point_i amount) {
    bool    ret;

    ret = ClapTrap::initEnergyPoint(amount, getName(), getType(), getEp());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool    FragTrap::initAttackDamage(Point_i amount) {
    bool    ret;

    ret = ClapTrap::initAttackDamage(amount, getName(), getType(), getAd());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool    FragTrap::setName(std::string target) {
    bool    ret;

    ret = ClapTrap::setName(target, getName(), getType());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}