/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:10:46 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 04:14:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

Character::Character(void): name("NULL"){
	slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++)
		slot[idx] = NULL;
	slotNum = 0;
	std::cout << name << " is created. : Default Constructor" << std::endl;
	printSlot();
}
Character::Character(const std::string name): name(name) {
	slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++)
		slot[idx] = NULL;
	slotNum = 0;
	std::cout << name << " is created. : Default Constructor" << std::endl;
	printSlot();
}
Character::Character(const Character& target): name(target.getName()) {
	slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++)
		slot[idx] = NULL;
	slotNum = 0;

	int idx = 0;
	while(target.slot[idx] != NULL) {
		slot[idx] = target.slot[idx]->clone();
		idx++;
	}
	slotNum = target.slotNum;
	std::cout << name << " is created. : Copy Constructor" << std::endl;
	printSlot();
}
Character::~Character(void){
	std::cout << name << " is deleted." << std::endl;
	
	int idx = 0;
	while(slot[idx] != NULL) 
		delete slot[idx++];
	delete[] slot;
	delete this;
}
Character&	Character::operator=(const Character& target){
	Character* temp = new Character(target.getName());
	slot = new AMateria*[4];

	int idx = 0;
	while(target.slot[idx] != NULL) {
		slot[idx] = target.slot[idx]->clone();
		idx++;
	}
	slotNum = target.slotNum;
	std::cout << name << " is created. : Copy Assign Operator" << std::endl;
	printSlot();
	return *this;
}

std::string const & Character::getName() const { return name; }

void Character::equip(AMateria* M) {
	if (M == NULL) return ;
	if (slotNum == 4) {
		std::cout << name << " has full slot of Materia."  << std::endl;
		return ;
	}

	int idx = 0;	

	while(idx < slotNum) idx++;
	slot[idx] = M;
	slotNum++;
	std::cout << name << " take Materia. : " << M->getType() << std::endl;
	printSlot();
	return ;
}
void Character::unequip(int idx) {
	AMateria* temp;
	temp = slot[idx];
	slot[idx] = NULL;
	while (idx < 4) {
		slot[idx] = slot[idx + 1];
		idx++;
	}
	std::cout << name << " putdown Materia. : " << temp->getType() << std::endl;
	printSlot();
}
void Character::use(int idx, ICharacter& target) {
	std::cout << name << " uses Materia! : " << slot[idx]->getType() << std::endl;
	slot[idx]->use(target);
	return ;
}
void Character::printSlot(void) const {
	std::cout << name << "'s Slot Status" << std::endl;
	std::cout << "===========================" << std::endl;
	for (int idx = 0; idx < 4 ; idx++) {
		if (slot[idx] != NULL) {
			std::cout << "[ " << idx << " ] " << slot[idx]->getType() << std::endl;
		}
		else
			std::cout << "[ " << idx << " ] " << "empty" << std::endl;
	}
	std::cout << "===========================" << std::endl;
}