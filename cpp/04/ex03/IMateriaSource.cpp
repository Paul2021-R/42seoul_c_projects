/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:47:13 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 15:13:01 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.hpp"

MateriaSource::MateriaSource(void) {
	slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++) slot[idx] = NULL;
	slotNum = 0;
	std::cout << "MateriaSource is ready : Deafualt Cosntructor" << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource& target) {
	slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++) slot[idx] = NULL;
	slotNum = 0;

	int idx = 0;
	while (target.slot[idx] != NULL) {
		if (target.slot[idx] != NULL)
			slot[idx] = target.slot[idx]->clone();
		if (target.slot[idx] == NULL)
			break ;
		slotNum++;
		idx++;
	}
	std::cout << "MateriaSource is ready : Deafualt Cosntructor" << std::endl;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& target) {
	MateriaSource* temp = new MateriaSource;
	temp->slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++) temp->slot[idx] = NULL;
	temp->slotNum = 0;

	int idx = 0;
	while (target.slot[idx] != NULL) {
		if (target.slot[idx] != NULL)
			temp->slot[idx] = target.slot[idx]->clone();
		if (target.slot[idx] == NULL)
			break ;
		temp->slotNum++;
		idx++;
	}
	return *temp;
}

MateriaSource::~MateriaSource(void) {
	int idx = 0;
	while (idx < slotNum) {
		delete slot[idx++];
	}
	delete[] slot;
}

void MateriaSource::learnMateria(AMateria* M) {
	int idx = 0;

	while (idx < slotNum) idx++;
	if (slotNum == 4)
		return ;
	slot[idx] = M;
	slotNum++;
	printMateriaSlot();
}
AMateria* MateriaSource::createMateria(std::string const & type) {
	int idx = 0;

	while (idx < 4) {
		if (slot[idx] != NULL && slot[idx]->getType().compare(type) == 0)
			return (slot[idx]->clone());
		else if (slot[idx] == NULL){
			std::cout << "Materia creation is failed" << std::endl;
			return (NULL);
		}
		idx++;
	}
	std::cout << "Slot is full." << std::endl;
	return (NULL);
}

void MateriaSource::printMateriaSlot(void) {
	std::cout << "MateriaSource Slot Status" << std::endl;
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