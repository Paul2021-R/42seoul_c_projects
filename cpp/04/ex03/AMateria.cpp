/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:28:06 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 05:13:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// AMateria::AMateria(void): type("default") {
// 	std::cout << type << " is created. : Default Constructor" << std::endl;
// }

// AMateria::AMateria(const AMateria& target): type(target.getType()) {
// 	std::cout << type << " is created. : Copy Constructor" << std::endl;
// }

// AMateria::~AMateria(void) {
// 	// std::cout << type << " is deleted." << std::endl;
// }

// AMateria&	AMateria::operator=(const AMateria& target) {
// 	type.clear();
// 	type.assign(target.getType());
// 	std::cout << type << " is created. : Copy Operator" << std::endl;
// 	return *this;
// }

// const std::string& AMateria::getType(void) const { return type; }

/////////////////////////////////////////////////////////////////////////////////////

Ice::Ice(void): type("ice") {
	std::cout << type << " is created. : Default Constructor" << std::endl;
}

Ice::Ice(const Ice& target): type(target.getType()) {
	std::cout << type << " is created. : Copy Constructor" << std::endl;
}

Ice::~Ice(void) {
	std::cout << type << " is deleted." << std::endl;
	delete this;
}

Ice	&Ice::operator=(const Ice& target) {
	type.clear();
	type.assign(target.getType());
	std::cout << type << " is created. : Copy Operator" << std::endl;
	return *this;
}

Ice* Ice::clone(void) const {
	Ice* temp = new Ice();
	return temp;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////

Cure::Cure(void): type("cure") {
	std::cout << type << " is created. : Default Constructor" << std::endl;
}

Cure::Cure(const Cure& target): type(target.getType()) {
	std::cout << type << " is created. : Copy Constructor" << std::endl;
}

Cure::~Cure(void) {
	std::cout << type << " is deleted." << std::endl;
	delete this;
}

Cure	&Cure::operator=(const Cure& target) {
	type.clear();
	type.assign(target.getType());
	std::cout << type << " is created. : Copy Operator" << std::endl;
	return *this;
}

Cure* Cure::clone(void) const {
	Cure* temp = new Cure();
	return temp;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}