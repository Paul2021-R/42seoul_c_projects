/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derived.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:25:59 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 21:03:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "derived.hpp"

Dog::Dog(void) {
	type = "Dog";
	std::cout << type << " is borned." << std::endl;
	myBrain = new Brain();
}
Dog::Dog(const Dog& target) {
	type = target.type;
	myBrain = new Brain(*target.myBrain);
	std::cout << getType() << " is borned(copy constructor)." << std::endl;
}
Dog::~Dog(void) {
	delete myBrain;
    std::cout << "Dog is died." << std::endl;
}
Dog&	Dog::operator=(const Dog& target) {
	type = target.getType();
	Brain* temp = new Brain(*target.myBrain);
	myBrain = temp;
    return (*this);
}
void            Dog::makeSound(void) const {
	std::cout << getType() << " makes sound : Wal! Wal!" << std::endl; 
}
void			Dog::setIdeas(const std::string& idea) {
	myBrain->setIdeas(idea);
}
void			Dog::setIdeas(const std::string& idea, int num) {
	myBrain->setIdeas(idea, num);
}
void			Dog::showIdeas(void) {
	std::cout << getType() << "'s ideas!!!" << std::endl;
	for (int idx= 0; idx < 100; idx++) {
		std::cout << idx << " : " << myBrain->getIdeas(idx) << std::endl;
	}
}
std::string&	Dog::getIdea(int num) {
	return (myBrain->getIdeas(num));
}

////////////////////////////////////////////////////////////////////////////////////

Cat::Cat(void) {
	type = "Cat";
	std::cout << type << " is borned." << std::endl;
	myBrain = new Brain();
}
Cat::Cat(const Cat& target) {
	type = target.type;
	myBrain = new Brain(*target.myBrain);
	std::cout << getType() << "is borned(copy constructor)." << std::endl;
}
Cat::~Cat(void) {
	delete myBrain;
    std::cout << "Cat is died." << std::endl;
}
Cat&	Cat::operator=(const Cat& target) {
    type = target.getType();
	Brain* temp = new Brain(*target.myBrain);
	myBrain = temp;
    return (*this);
}
void	Cat::makeSound(void) const { std::cout << getType() << " maked sound : meow!" << std::endl; }
void			Cat::setIdeas(const std::string& idea) {
	myBrain->setIdeas(idea);
}
void			Cat::setIdeas(const std::string& idea, int num) {
	myBrain->setIdeas(idea, num);
}
void			Cat::showIdeas(void) {
	std::cout << getType() << "'s ideas!!!" << std::endl;
	for (int idx= 0; idx < 100; idx++) {
		std::cout << idx << " : " << myBrain->getIdeas(idx) << std::endl;
	}
}
std::string&			Cat::getIdea(int num) {
	return (myBrain->getIdeas(num));
}
