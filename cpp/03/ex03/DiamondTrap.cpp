/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:48:28 by haryu             #+#    #+#             */
/*   Updated: 2022/10/08 02:22:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap(),
	ScavTrap(),
	FragTrap(),
	name("default"),
	type("DiamondTrap"),
	hitPoint(FragTrap::getHp()),
	energyPoint(ScavTrap::getEp()),
	attackDamage(FragTrap::getAd()){
	ClapTrap::setName("default_clap_name");
	std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
DiamondTrap::DiamondTrap(std::string name) :
 	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name),
	name(name),
	type("DiamondTrap"),
	hitPoint(FragTrap::getHp()),
	energyPoint(ScavTrap::getEp()),
	attackDamage(FragTrap::getAd()) {
	name.append("_clap_name");
	ClapTrap::setName(name);
	std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
DiamondTrap::DiamondTrap(const DiamondTrap& target) :
	ClapTrap(target.name),
	ScavTrap(target.name),
	FragTrap(target.name),
	name(target.name),
	type("DiamondTrap"),
	hitPoint(FragTrap::getHp()),
	energyPoint(ScavTrap::getEp()),
	attackDamage(FragTrap::getAd()) {
	ClapTrap::name.append("_clap_name");
	std::cout << type << " : Copy constructor operated" << std::endl;
    printConstructor(getName(), getType(), getHp(), getEp(), getAd());
}
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& target) {
	name.assign(target.name);
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << type << " : Copy Assign operator operated" << std::endl;
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return *this;
}
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap \" " << name << " \" is destroyed" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am \" " << name << " \"" << " My ClapTrap Name is \"" << ClapTrap::getName() << " \"" << std::endl;
}

void	DiamondTrap::guardGate(void) {
	ScavTrap::guardGate(getName(), getType(), getHp(), getEp(), getAd());
}

void	DiamondTrap::highFiveGuys(void) {
	FragTrap::highFiveGuys(getName(), getType());
}

void    DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
void    DiamondTrap::takeDamage(Point_i amount) {
    ClapTrap::takeDamage(amount, getName(), getType(), getHp());
}
void    DiamondTrap::beRepaired(Point_i amount) {
    ClapTrap::beRepaired(amount, getName(), getType(), getHp(), getEp());
}

bool    DiamondTrap::initHitPoint(Point_i amount) {
    bool    ret;
    
    ret = ClapTrap::initHitPoint(amount, getName(), getType(), getHp());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool    DiamondTrap::initEnergyPoint(Point_i amount) {
    bool    ret;

    ret = ClapTrap::initEnergyPoint(amount, getName(), getType(), getEp());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool    DiamondTrap::initAttackDamage(Point_i amount) {
    bool    ret;

    ret = ClapTrap::initAttackDamage(amount, getName(), getType(), getAd());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}
bool    DiamondTrap::setName(std::string target) {
    bool    ret;

    ret = ClapTrap::setName(target, getName(), getType());
    ClapTrap::printConstructor(getName(), getType(), getHp(), getEp(), getAd());
    return (ret);
}