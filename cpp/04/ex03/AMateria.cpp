/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:28:06 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 15:21:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.hpp"

Ice::Ice(void): type("ice") {
	std::cout << type << " is created. : Default Constructor" << std::endl;
}

Ice::Ice(const Ice& target): type(target.getType()) {
	std::cout << type << " is created. : Copy Constructor" << std::endl;
}

Ice::~Ice(void) {
	std::cout << type << " is deleted." << std::endl;
}

Ice	&Ice::operator=(const Ice& target) {
	type.clear();
	type.assign(target.getType());
	std::cout << type << " is created. : Copy Operator" << std::endl;
	return *this;
}

AMateria* Ice::clone(void) const {
	AMateria* temp = new Ice();
	return temp;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

const std::string& Ice::getType(void) const { return type; }

/////////////////////////////////////////////////////////////////////////////////////

Cure::Cure(void): type("cure") {
	std::cout << type << " is created. : Default Constructor" << std::endl;
}

Cure::Cure(const Cure& target): type(target.getType()) {
	std::cout << type << " is created. : Copy Constructor" << std::endl;
}

Cure::~Cure(void) {
	std::cout << type << " is deleted." << std::endl;
}

Cure	&Cure::operator=(const Cure& target) {
	type.clear();
	type.assign(target.getType());
	std::cout << type << " is created. : Copy Operator" << std::endl;
	return *this;
}

AMateria* Cure::clone(void) const {
	AMateria* temp = new Cure();
	return temp;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

const std::string& Cure::getType(void) const { return type; }