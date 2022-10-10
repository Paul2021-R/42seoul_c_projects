/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:32:45 by haryu             #+#    #+#             */
/*   Updated: 2022/10/10 20:40:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("none") { std::cout << type << " is borned." << std::endl; }
Animal::Animal(const std::string& target): type(target) { }
Animal::Animal(const Animal& target): type(target.type) {
    std::cout << getType() << " is borned(copy constructor)." << std::endl;
}
Animal::~Animal(void) {}
Animal&	Animal::operator=(const Animal& target) {
    Animal* temp = new Animal(target);
    std::cout << getType() << "is borned(copy asign)." << std::endl;
    return *temp;
}

void    Animal::makeSound(void) const { std::cout << getType() << " can't make sound." << std::endl; }
const std::string& Animal::getType(void) const { return type; }

////////////////////////////////////////////////////////////////////////////////////

Dog::Dog(void): Animal("Dog") {
    std::cout << getType() << " is borned." << std::endl;
}
Dog::Dog(const Dog& target): Animal(target) {std::cout << getType() << " is borned(copy constructor)." << std::endl; }
Dog::~Dog(void) {
    std::cout << "Dog is died." << std::endl;
}
Dog&	Dog::operator=(const Dog& target) {
    Dog* temp = new Dog(target);
    return *temp;
}

void            Dog::makeSound(void) const { std::cout << getType() << " maked sound : Wal! Wal!" << std::endl; }
const std::string&    Dog::getType(void) const { return type; } 

////////////////////////////////////////////////////////////////////////////////////

// Cat::Cat(void): Animal(), type("Cat") {
//     std::cout << getType() << "is borned." << std::endl;
// }
// Cat::Cat(const Cat& target): Animal(target) {std::cout << getType() << "is borned(copy constructor)." << std::endl; }
// Cat::~Cat(void) {
//     std::cout << "Cat is died." << std::endl;
//     delete this;
// }
// Cat&	Cat::operator=(const Cat& target) {
//     Cat* temp = new Cat(target);
//     return temp;
// }
// void            Cat::makeSound(void) { std::cout << getType() << " maked sound : meow!" << std::endl; }
// std::string&    Cat::getType(void) { return type; } 
