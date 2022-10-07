/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:48:28 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 02:40:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap(),
	ScavTrap(),
	FragTrap(),
	name(ClapTrap::name),
	hitPoint(ClapTrap::hitPoint),
	eneregyPoint(ScavTrap::energyPoint),
	attackDamage(FragTrap::attackDamage){
	type.assign("DiamondTrap");
	ClapTrap::name.append("_clap_name");
	std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}
DiamondTrap::DiamondTrap(std::string name) :
 	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name),
	name(name),
	hitPoint(ClapTrap::hitPoint),
	eneregyPoint(ScavTrap::energyPoint),
	attackDamage(FragTrap::attackDamage) {
	type.assign("DiamondTrap");
	ClapTrap::name.append("_clap_name");
	std::cout << type << " : Default Constructor operated." << std::endl;
    printConstructor(type);
}
DiamondTrap::DiamondTrap(const DiamondTrap& target) :
	ClapTrap(target.name, target.hitPoint, target.eneregyPoint, target.attackDamage),
	ScavTrap(target.name, target.hitPoint, target.eneregyPoint, target.attackDamage),
	FragTrap(target.name, target.hitPoint, target.eneregyPoint, target.attackDamage),
	name(target.name),
	hitPoint(ClapTrap::hitPoint),
	eneregyPoint(ScavTrap::energyPoint),
	attackDamage(FragTrap::attackDamage){
	type.assign("DiamondTrap");
	ClapTrap::name.append("_clap_name");
	std::cout << type << " : Copy constructor operated" << std::endl;
    printConstructor(type);
}
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap \" " << name << " \" is destroyed" << std::endl;
}
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& target) {
	name = target.name;
	std::string temp(target.name);
	ClapTrap::name.assign(temp.append("_clap_name"));
	hitPoint = target.hitPoint;
	eneregyPoint = target.eneregyPoint;
	attackDamage = target.attackDamage;
	std::cout << type << " : Copy Assign operator operated" << std::endl;
	printConstructor(type);
	return *this;
}
void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI(void) {
	std::cout << name << " " << ClapTrap::name << std::endl;
}

void	DiamondTrap::printConstructor(std::string type) {
	std::cout << YELLOW;
	std::cout << "\n=====================================" << std::endl << WHITE;
	std::cout << type << " : \" " << name << " \" " << std::endl;
	std::cout << GREEN << "Hit Point : " << hitPoint << std::endl;
	std::cout << BLUE << "Energy Point : " << energyPoint << std::endl;
	std::cout << RED << "Attack Damage : " << attackDamage << std::endl;
	std::cout << YELLOW << "=====================================\n" << WHITE << std::endl;
}