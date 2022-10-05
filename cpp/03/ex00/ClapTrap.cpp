/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:35:29 by haryu             #+#    #+#             */
/*   Updated: 2022/10/05 16:43:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	hitPoint(10),
	energyPoint(10),
	attackDamage(0)
{
	name = "default";
	std::cout << "Default Constructor operated." << std::endl;
	printConstructor();
}

ClapTrap::ClapTrap(std::string name):
	name(name),
	hitPoint(10),
	energyPoint(10),
	attackDamage(0)
{
	std::cout << "Default Constructor operated." << std::endl;
	printConstructor();
}

ClapTrap::ClapTrap(std::string name, Point_i hp, Point_i ep, Point_i ad):
	name(name),
	hitPoint(hp),
	energyPoint(ep),
	attackDamage(ad)
{
	printConstructor();
}

ClapTrap::ClapTrap(const ClapTrap& target){
	name.clear();
	name.assign(target.name);
	hitPoint = target.hitPoint;
	energyPoint = target.energyPoint;
	attackDamage = target.attackDamage;
	std::cout << "Copy constructor operated" << std::endl;
	printConstructor();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& target) {
	name.clear();
	name.assign(target.name);
	hitPoint = target.hitPoint;
	energyPoint = target.energyPoint;
	attackDamage = target.attackDamage;
	std::cout << "Copy Assign operator operated" << std::endl;
	printConstructor();

	return *this;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap : \" " << name << " \" is destroyed" << std::endl;
}

bool	ClapTrap::useEnergy(void) {
	if (energyPoint == 0){ return (false); }
	
	--energyPoint;
	return (true);
}

void	ClapTrap::attack(const std::string& target) {
	if (hitPoint == 0) { printAttack(target, 0); }
	else if (useEnergy()) { printAttack(target, 1); }
	else { printAttack(target, 2); }
	return ;
}

void	ClapTrap::takeDamage(Point_i amount) {
	if (hitPoint == 0) { printTakeDamage(amount, 0); }
	else {
		if (amount >= hitPoint) { hitPoint = 0; }
		else { hitPoint -= amount; }
		printTakeDamage(amount, 1);
	}
	return ;
}

void	ClapTrap::beRepaired(Point_i amount) {
	if (hitPoint == 0) { printBeRepaired(amount, 0); }
	else if (useEnergy()) {
		printBeRepaired(amount, 1);
		hitPoint += amount;
	}
	else { printBeRepaired(amount, 2); }
	return ;
}

bool	ClapTrap::initHitPoint(Point_i amount) {
	hitPoint = amount;
	std::cout << "\nSYSTEM : ClapTrap : " << name << " set Hit Point : " << GREEN  << amount << WHITE  << std::endl;
	printConstructor();
	return (true);
}

bool	ClapTrap::initEnergyPoint(Point_i amount) {
	energyPoint = amount;
	std::cout << "\nSYSTEM : ClapTrap : " << name << " set Energy Point : "  << BLUE << amount << WHITE << std::endl;
	printConstructor();
	return (true);
}

bool	ClapTrap::initAttackDamage(Point_i amount) {
	attackDamage = amount;
	std::cout << "\nSYSTEM : ClapTrap : " << name << " set Attack Damage : " << RED << amount << WHITE << std::endl;
	printConstructor();
	return (true);
}

bool	ClapTrap::setName(std::string target) {
	name.clear();
	name.assign(target);
	std::cout << "\nSYSTEM : ClapTrap : " << name << " set his name : \" " << YELLOW << target << WHITE << " \" " << std::endl;
	printConstructor();
	return (true);
}


void	ClapTrap::printBeRepaired(Point_i amount, int code) {
	std::cout << GREEN;
	switch (code) {
		case 0 :
			std::cout << "ClapTrap : \" " << name << " \" is failed to be repaired : " << amount << " : HP is 0" << std::endl;
			break ;
		case 1 : 
			std::cout << "ClapTrap : \" " << name << " \" is repaired : " << amount << std::endl;
			break ;
		default : 
			std::cout << "ClapTrap : \" " << name << " \" is failed to be repaired : " << amount << " : EP is 0" << std::endl;
	}
	std::cout << WHITE;
}

void	ClapTrap::printTakeDamage(Point_i amount, int code) {
	std::cout << RED;
	switch (code) {
		case 0 :
			std::cout << "ClapTrap : \" " << name << " \" is already nocked out" << std::endl;
			break ;
		default :
			std::cout << "ClapTrap : \" " << name << " \" taked damage : " << amount;
			if (hitPoint == 0) { std::cout << " : HP is 0";}
			std::cout << std::endl;
	}
	std::cout << WHITE;
}

void	ClapTrap::printAttack(const std::string& target, const int code) {
	std::cout << CYAN;
	switch (code) {
		case 0 :
			std::cout << "ClapTrap : \" " << name << " \" is failed to attack. : [ " << target << " ] : HP is 0" << std::endl;
			break ;
		case 1 :
			std::cout << "ClapTrap : \" " << name << " \" attacks [ " << target << " ] : " << attackDamage << std::endl;
			break ;
		default :
			std::cout << "ClapTrap : \" " << name << " \" is failed to attack : [ " << target << " ] : EP is 0" << std::endl;
			break ;
	}
	std::cout << WHITE;	
}

void	ClapTrap::printConstructor(void) {
	std::cout << YELLOW;
	std::cout << "\n=====================================" << std::endl << WHITE;
	std::cout << "ClapTrap : " << name << std::endl;
	std::cout << GREEN << "Hit Point : " << hitPoint << std::endl;
	std::cout << BLUE << "Energy Point : " << energyPoint << std::endl;
	std::cout << RED << "Attack Damage : " << attackDamage << std::endl;
	std::cout << YELLOW << "=====================================\n" << WHITE << std::endl;
}