/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:35:29 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 01:44:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	name("default"),
	type("ClapTrap"),
	hitPoint(10),
	energyPoint(10),
	attackDamage(0)
{
	std::cout << "Default Constructor operated." << std::endl;
	printConstructor(type);
}

ClapTrap::ClapTrap(std::string name):
	name(name),
	type("ClapTrap"),
	hitPoint(10),
	energyPoint(10),
	attackDamage(0)
{
	std::cout << "Default Constructor operated." << std::endl;
	printConstructor(type);
}

ClapTrap::ClapTrap(std::string name, Point_i hp, Point_i ep, Point_i ad):
	name(name),
	type("ClapTrap"),
	hitPoint(hp),
	energyPoint(ep),
	attackDamage(ad)
{
	std::cout << "Default Constructor operated." << std::endl;
	printConstructor(type);
}

ClapTrap::ClapTrap(const ClapTrap& target){
	name.clear();
	name.assign(target.name);
	type.clear();
	type.assign(target.type);
	hitPoint = target.hitPoint;
	energyPoint = target.energyPoint;
	attackDamage = target.attackDamage;
	std::cout << "Copy constructor operated" << std::endl;
	printConstructor(type);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& target) {
	name.clear();
	name.assign(target.name);
	type.clear();
	type.assign(target.type);
	hitPoint = target.hitPoint;
	energyPoint = target.energyPoint;
	attackDamage = target.attackDamage;
	std::cout << "Copy Assign operator operated" << std::endl;
	printConstructor(type);

	return *this;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap \" " << name << " \" is destroyed" << std::endl;
}

/////////////////////////////////////////////////////

bool	ClapTrap::useEnergy(void) {
	if (energyPoint == 0){ return (false);}
	--energyPoint;
	return (true);
}

bool	ClapTrap::useEnergy(Point_i& ep) {
	if (ep == 0){ return (false);}
	--ep;
	return (true);
}

/////////////////////////////////////////////////////

void	ClapTrap::attack(const std::string& target) {
	if (hitPoint == 0) { printAttack(target, 0); }
	else if (useEnergy()) { printAttack(target, 1); }
	else { printAttack(target, 2); }
	return ;
}
void	ClapTrap::attack(const std::string& target, const std::string name_, const std::string& type_, const Point_i hp, Point_i& ep, const Point_i ad){
	if (hp == 0) { printAttack(target, 0, name_, type, ad); }
	else if (useEnergy(ep)) { printAttack(target, 1, name_, type_, ad); }
	else { printAttack(target, 2, name_, type_, ad); }
	return ;
}

/////////////////////////////////////////////////////

void	ClapTrap::takeDamage(Point_i amount) {
	if (hitPoint == 0) { printTakeDamage(amount, 0); }
	else {
		if (amount >= hitPoint) { hitPoint = 0; }
		else { hitPoint -= amount; }
		printTakeDamage(amount, 1);
	}
	return ;
}
void	ClapTrap::takeDamage(Point_i amount, const std::string& name_, const std::string& type_, Point_i& hp) {
	if (hp == 0) { printTakeDamage(amount, 0, name_, type_, hp); }
	else {
		if (amount >= hp) { hp = 0; }
		else { hp -= amount; }
		printTakeDamage(amount, 0, name_, type_, hp);
	}
	return ;
}

/////////////////////////////////////////////////////

void	ClapTrap::beRepaired(Point_i amount) {
	if (hitPoint == 0) { printBeRepaired(amount, 0); }
	else if (useEnergy()) {
		printBeRepaired(amount, 1);
		hitPoint += amount;
	}
	else { printBeRepaired(amount, 2); }
	return ;
}

void	ClapTrap::beRepaired(Point_i amount, const std::string name_, const std::string& type_, Point_i& hp, Point_i& ep) {
	if (hp == 0) { printBeRepaired(amount, 0, name_, type_); }
	else if (useEnergy(ep)) {
		printBeRepaired(amount, 0, name_, type_);
		hp += amount;
	}
	else { printBeRepaired(amount, 0, name_, type_); }
	return ;
}

/////////////////////////////////////////////////////

bool	ClapTrap::initHitPoint(Point_i amount) {
	hitPoint = amount;
	std::cout << "SYSTEM : " << type << " : \" " << name << " \" set Hit Point : " << GREEN  << amount << WHITE  << std::endl;
	printConstructor(type);
	return (true);
}

bool	ClapTrap::initHitPoint(Point_i amount, const std::string& name_, const std::string& type_, Point_i& hp) {
	hp = amount;
	std::cout << "SYSTEM : " << type_ << " : \" " << name_ << " \" set Hit Point : " << GREEN  << amount << WHITE  << std::endl;
	return (true);
}

bool	ClapTrap::initEnergyPoint(Point_i amount) {
	energyPoint = amount;
	std::cout << "SYSTEM : " << type << " : \" " << name << " \" set Energy Point : "  << BLUE << amount << WHITE << std::endl;
	printConstructor(type);
	return (true);
}

bool	ClapTrap::initEnergyPoint(Point_i amount, const std::string& name_, const std::string& type_, Point_i& ep) {
	ep = amount;
	std::cout << "SYSTEM : " << type_ << " : \" " << name_ << " \" set Energy Point : "  << BLUE << amount << WHITE << std::endl;
	return (true);
}

bool	ClapTrap::initAttackDamage(Point_i amount) {
	attackDamage = amount;
	std::cout << "SYSTEM : " << type << " : \" " << name << " \" set Attack Damage : " << RED << amount << WHITE << std::endl;
	printConstructor(type);
	return (true);
}

bool	ClapTrap::initAttackDamage(Point_i amount, const std::string& name_, const std::string& type_, Point_i& ad) {
	ad = amount;
	std::cout << "SYSTEM : " << type_ << " : \" " << name_ << " \" set Attack Damage : " << RED << amount << WHITE << std::endl;
	return (true);
}

bool	ClapTrap::setName(std::string target) {
	std::cout << "SYSTEM : " << type << " : \" " << name << " \" set his name : \" " << YELLOW << target << WHITE << " \" " << std::endl;
	name.clear();
	name.assign(target);
	printConstructor(type);
	return (true);
}

bool	ClapTrap::setName(std::string target, std::string& name_, const std::string& type_) {
	std::cout << "SYSTEM : " << type_ << " : \" " << name_ << " \" set his name : \" " << YELLOW << target << WHITE << " \" " << std::endl;
	name_.clear();
	name_.assign(target);
	return (true);
}


/////////////////////////////////////////////////////

void	ClapTrap::printBeRepaired(Point_i amount, int code) {
	std::cout << GREEN;
	switch (code) {
		case 0 :
			std::cout << type << " \" " << name << " \" is failed to be repaired : " << amount << " : HP is 0" << std::endl;
			break ;
		case 1 : 
			std::cout << type << " \" " << name << " \" is repaired : " << amount << std::endl;
			break ;
		default : 
			std::cout << type << " \" " << name << " \" is failed to be repaired : " << amount << " : EP is 0" << std::endl;
	}
	std::cout << WHITE;
}

void	ClapTrap::printBeRepaired(Point_i amount, int code, const std::string& name_, const std::string& type_) {
	std::cout << GREEN;
	switch (code) {
		case 0 :
			std::cout << type_ << " \" " << name_ << " \" is failed to be repaired : " << amount << " : HP is 0" << std::endl;
			break ;
		case 1 : 
			std::cout << type_ << " \" " << name_ << " \" is repaired : " << amount << std::endl;
			break ;
		default : 
			std::cout << type_ << " \" " << name_ << " \" is failed to be repaired : " << amount << " : EP is 0" << std::endl;
	}
	std::cout << WHITE;
}

/////////////////////////////////////////////////////

void	ClapTrap::printTakeDamage(Point_i amount, int code) {
	std::cout << RED;
	switch (code) {
		case 0 :
			std::cout << type << " \" " << name << " \" is already nocked out" << std::endl;
			break ;
		default :
			std::cout << type << " \" " << name << " \" taked damage : " << amount;
			if (hitPoint == 0) { std::cout << " : HP is 0";}
			std::cout << std::endl;
	}
	std::cout << WHITE;
}

void	ClapTrap::printTakeDamage(Point_i amount, int code, const std::string name_, const std::string type_, const Point_i& hp) {
	std::cout << RED;
	switch (code) {
		case 0 :
			std::cout << type_ << " \" " << name_ << " \" is already nocked out" << std::endl;
			break ;
		default :
			std::cout << type_ << " \" " << name_ << " \" taked damage : " << amount;
			if (hp == 0) { std::cout << " : HP is 0";}
			std::cout << std::endl;
	}
	std::cout << WHITE;
}

/////////////////////////////////////////////////////

void	ClapTrap::printAttack(const std::string& target, const int code) {
	std::cout << CYAN;
	switch (code) {
		case 0 :
			std::cout << type << " \" " << name << " \" is failed to attack. : [ " << target << " ] : HP is 0" << std::endl;
			break ;
		case 1 :
			std::cout << type << " \" " << name << " \" attacks [ " << target << " ] : " << attackDamage << std::endl;
			break ;
		default :
			std::cout << type << " \" " << name << " \" is failed to attack : [ " << target << " ] : EP is 0" << std::endl;
			break ;
	}
	std::cout << WHITE;	
}

void	ClapTrap::printAttack(const std::string& target, const int code, const std::string& name_, const std::string& type_, const Point_i ad) {
	std::cout << CYAN;
	switch (code) {
		case 0 :
			std::cout << type_ << " \" " << name_ << " \" is failed to attack. : [ " << target << " ] : HP is 0" << std::endl;
			break ;
		case 1 :
			std::cout << type_ << " \" " << name_ << " \" attacks [ " << target << " ] : " << ad << std::endl;
			break ;
		default :
			std::cout << type_ << " \" " << name_ << " \" is failed to attack : [ " << target << " ] : EP is 0" << std::endl;
			break ;
	}
	std::cout << WHITE;	
}

/////////////////////////////////////////////////////

void	ClapTrap::printConstructor(std::string type) {
	std::cout << YELLOW;
	std::cout << "\n=====================================" << std::endl << WHITE;
	std::cout << type << " : \" " << name << " \" " << std::endl;
	std::cout << GREEN << "Hit Point : " << hitPoint << std::endl;
	std::cout << BLUE << "Energy Point : " << energyPoint << std::endl;
	std::cout << RED << "Attack Damage : " << attackDamage << std::endl;
	std::cout << YELLOW << "=====================================\n" << WHITE << std::endl;
}

void	ClapTrap::printConstructor(std::string name_, std::string type_, Point_i hp, Point_i ep, Point_i ad) const {
	std::cout << YELLOW;
	std::cout << "\n=====================================" << std::endl << WHITE;
	std::cout << type_ << " : \" " << name_ << " \" " << std::endl;
	std::cout << GREEN << "Hit Point : " << hp << std::endl;
	std::cout << BLUE << "Energy Point : " << ep << std::endl;
	std::cout << RED << "Attack Damage : " << ad << std::endl;
	std::cout << YELLOW << "=====================================\n" << WHITE << std::endl;
}

/////////////////////////////////////////////////////