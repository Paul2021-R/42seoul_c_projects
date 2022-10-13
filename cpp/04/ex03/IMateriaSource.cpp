/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:47:13 by haryu             #+#    #+#             */
/*   Updated: 2022/10/14 05:02:08 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	slot = new AMateria*[4];
	for (int idx = 0; idx < 4; idx++) slot[idx] = NULL;
	slotNum = 0;
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
	while (slot[idx] != NULL) {
		delete slot[idx++];
	}
	delete[] slot;
	delete this;
}

void MateriaSource::learnMateria(AMateria* M) {
	int idx = 0;

	while (idx < slotNum) idx++;
	if (idx == 4 && slotNum == 4)
		return ;
	slot[idx] = M->clone();
	slotNum++;
}
AMateria* MateriaSource::createMateria(std::string const & type) {
	int idx = 0;

	while (idx < 4 && slot[idx] != NULL) {
		if (slot[idx]->getType().compare(type) == 0)
			return (slot[idx]->clone());
		idx++;
	}
}