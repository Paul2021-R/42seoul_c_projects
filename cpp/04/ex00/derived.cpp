/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derived.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:25:59 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 15:29:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derived.hpp"

Dog::Dog(void): Animal("Dog") {}
Dog::Dog(const Dog& target): Animal(target) {
	std::cout << getType() << " is borned(copy constructor)." << std::endl; 
}
Dog::~Dog(void) {
    std::cout << "Dog is died." << std::endl;
}
Dog&	Dog::operator=(const Dog& target) {
    return ((Dog&)target);
}
void            Dog::makeSound(void) const { std::cout << getType() << " makes sound : Wal! Wal!" << std::endl; }

////////////////////////////////////////////////////////////////////////////////////

Cat::Cat(void): Animal("Cat") {}
Cat::Cat(const Cat& target): Animal(target) {
	std::cout << getType() << "is borned(copy constructor)." << std::endl; 
}
Cat::~Cat(void) {
    std::cout << "Cat is died." << std::endl;
}
Cat&	Cat::operator=(const Cat& target) {
    return (Cat&)target;
}
void	Cat::makeSound(void) const { std::cout << getType() << " maked sound : meow!" << std::endl; }
