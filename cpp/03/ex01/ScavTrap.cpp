/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:47 by haryu             #+#    #+#             */
/*   Updated: 2022/10/05 18:26:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << "ScavTrap : Default Constructor operated." << std::endl;
    printConstructor();
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap : Default Constructor operated." << std::endl;
    printConstructor();
}
ScavTrap::ScavTrap(const ScavTrap& target) : 
    ClapTrap(target.name)
{
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << "ScavTrap : Copy constructor operated" << std::endl;
    printConstructor();
}
ScavTrap& ScavTrap::operator=(const ScavTrap& target) {
    name.clear();
    name.assign(target.name);
    hitPoint = target.hitPoint;
    energyPoint = target.energyPoint;
    attackDamage = target.attackDamage;
    std::cout << "ScavTrap : Copy Assign operator operated" << std::endl;
    printConstructor();
    
    return *this;
}
ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap : \" " << name << " \" is destroyed" << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << PURPLE << "\n <<< ScavTrap's Guard Gate Mode >>>" << std::endl;
    std::cout << "=====================================" << std::endl << WHITE;
    std::cout << "ClapTrap : " << name << std::endl;
    std::cout << GREEN << "Hit Point : " << hitPoint << std::endl;
    std::cout << BLUE << "Energy Point : " << energyPoint << std::endl;
    std::cout << RED << "Attack Damage : " << attackDamage << WHITE <<std::endl;
    std::cout << PURPLE << "=====================================" << std::endl;
    std::cout << "\n" << WHITE << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    std::cout << PURPLE << "ScavTrap : ";
    ClapTrap::attack(target);
}
void    ScavTrap::takeDamage(Point_i amount) {
    std::cout << PURPLE << "ScavTrap : ";
    ClapTrap::takeDamage(amount);
}
void    ScavTrap::beRepaired(Point_i amount) {
    std::cout << PURPLE << "ScavTrap : ";
    ClapTrap::beRepaired(amount);
}

bool   ScavTrap::initHitPoint(Point_i amount) {
    std::cout << PURPLE << "ScavTrap : ";
    return (ClapTrap::initHitPoint(amount));
}

bool    ScavTrap::initAttackDamage(Point_i amount){
    std::cout << PURPLE << "ScavTrap : ";
    return (ClapTrap::initAttackDamage(amount));
}

bool    ScavTrap::initEnergyPoint(Point_i amount){
    std::cout << PURPLE << "ScavTrap : ";
    return (ClapTrap::initEnergyPoint(amount));
}

void   ScavTrap::printConstructor(void) {
    guardGate();
}