/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:35:29 by haryu             #+#    #+#             */
/*   Updated: 2022/10/03 17:54:57 by haryu            ###   ########.fr       */
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

ClapTrap::ClapTrap(std::string name, Point_i hp, Point_i ep, Point_i ad):
	name(name),
	hitPoint(hp),
	energyPoint(ep),
	attackDamage(ad)
{
	printConstructor();
}

ClapTrap::ClapTrap(ClapTrap &target){
	name.clear();
	name.assign(target.name);
	hitPoint = target.hitPoint;
	energyPoint = target.energyPoint;
	attackDamage = target.attackDamage;
	std::cout << "Copy constructor operated" << std::endl;
	printConstructor();
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap(" << name << ") is destroyed." << std::endl;
}

/**
 * @brief 얕은 복사로 진행함. 이는 동적 할당을 따로 고려한 생성자까지 만들지 않기 위해서다. 
 * 
 * @param target 
 * @return ClapTrap& 
 */
ClapTrap	&ClapTrap::operator=(ClapTrap &target){	
	return (target);
}

void	ClapTrap::printConstructor(void) {
	std::cout << "=====================================" << std::endl;
	std::cout << "ClapTrap : " << name << std::endl;
	std::cout << "Hit Point : " << hitPoint << std::endl;
	std::cout << "Energy Point : " << energyPoint << std::endl;
	std::cout << "Attack Damage : " << attackDamage << std::endl;
	std::cout << "=====================================" << std::endl;
}

bool	ClapTrap::useEnergy(void) {
	if (energyPoint == 0){
		std::cout << "ClapTrap : " << name << std::endl;
		std::cout << "Not enough Energy." << std::endl;
		return (false);
	}
	std::cout << "ClapTrap : " << name << std::endl;
	std::cout << "Use " << name << "'s Energy : " << --energyPoint << std::endl;
	return (true);
}

void	ClapTrap::attack(const std::string& target) {
	if (hitPoint == 0) {
		std::cout << "ClapTrap : " << name << " is nockedout." << std::endl;
		return ;
	}
	if (useEnergy()) {
		std::cout << "ClapTrap : " << name << " attacks " << target << " with " << attackDamage << " points of attack" << std::endl;
		printConstructor();
		return ;
	}
	else {
		std::cout << "ClapTrap" << name << " is failed to attack " << target  << std::endl;
		return ;
	}
}

void	ClapTrap::takeDamange(Point_i amount) {
	if (hitPoint == 0) {
		std::cout << "ClapTrap : " << name << "is nockedout." << std::endl;
		return ;
	}
	std::cout << "ClapTrap : " << name << " is attacked with " << amount << "of Damage." << std::endl;
	if (amount >= hitPoint) {
		hitPoint = 0;
		std::cout << "ClapTrap : " << name << " is nocked out." << std::endl;
		printConstructor();
	}
	else {
		hitPoint -= amount;
	}
	return ;
}

void	ClapTrap::beRepaired(Point_i amount) {
	if (useEnergy()) {
		std::cout << "ClapTrap : " << name << " is repaired" << amount << std::endl;
		hitPoint += amount;
		printConstructor();
		return ;
	}
	else {
		std::cout << "ClapTrap : " << name << " is failed to be repaired." << amount << std::endl;
		return ;
	}
}

bool	ClapTrap::initHitPoint(Point_i amount) {
	hitPoint = amount;
	std::cout << "ClapTrap : " << name << " set hitpoint" << std::endl;
	printConstructor();
	return (true);
}

bool	ClapTrap::initEnergyPoint(Point_i amount) {
	energyPoint = amount;
	std::cout << "ClapTrap : " << name << " set energy point" << std::endl;
	printConstructor();
	return (true);
}

bool	ClapTrap::initAttackDamage(Point_i amount) {
	attackDamage = amount;
	std::cout << "ClapTrap : " << name << " set attack damage" << std::endl;
	printConstructor();
	return (true);
}

bool	ClapTrap::setName(std::string target) {
	name.clear();
	name.assign(target);
	std::cout << "ClapTrap : " << name << " set his name" << std::endl;
	printConstructor();
	return (true);
}
