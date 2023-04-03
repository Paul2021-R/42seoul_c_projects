/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:59 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 15:33:01 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

Animal::Animal(void): type("Wrong") {
	std::cout << type << " is borned." << std::endl;
}
Animal::Animal(const std::string& target): type("Wrong") {
	(void)target;
	std::cout << type << " is borned." << std::endl;
}
Animal::Animal(const Animal& target): type(target.type) {
	std::cout << type << " is borned." << std::endl; 
}
Animal::~Animal(void) {
	std::cout << "Wrong animal is died." << std::endl;
}
Animal& Animal::operator=(const Animal& target) {
	return ((Animal&)target);
}
void	Animal::makeSound(void) const {
	std::cout << "This is not virtual function." << std::endl;
}
const std::string& Animal::getType() const { return type; }