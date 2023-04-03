/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:45 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 15:33:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("none") { 
	std::cout << type << " is borned." << std::endl;
}

Animal::Animal(const std::string& target): type(target) {
	std::cout << type << " is borned." << std::endl; 
}

Animal::Animal(const Animal& target): type(target.type) {
    std::cout << getType() << " is borned(copy constructor)." << std::endl;
}
Animal::~Animal(void) {
	std::cout << "Some animal is died." << std::endl;
}

Animal&	Animal::operator=(const Animal& target) {
	return (Animal&)target;
}

void       Animal::makeSound(void) const {
	std::cout << getType() << " can not make Sound." << std::endl;
}

const std::string& Animal::getType(void) const { return type; }
