/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:15:02 by haryu             #+#    #+#             */
/*   Updated: 2022/10/12 17:07:01 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain(void) {
	std::cout << "Ideas are ready." << " : Default" << std::endl;
	ideas = new std::string[100];
	for (int idx = 0; idx < 100; idx++) {
		ideas[idx].assign("blah..blah..");
	}
}

Brain::Brain(const Brain& target) {
	std::cout << "Ideas are ready." << " : copy Constuctor" << std::endl;
	ideas = new std::string[100];
	for (int idx = 0; idx < 100; idx++) {
		ideas[idx].assign(target.ideas[idx]);
	}
}

Brain::~Brain(void) {
	std::cout << "Brains is melt down.... = =" << std::endl;
	for (int idx = 0; idx < 100; idx++) {
		ideas[idx].clear();
	}
	delete[] ideas;
}

Brain	&Brain::operator=(const Brain& target) {
	std::cout << "Ideas are ready." << " : copy assign" << std::endl;
	for (int idx = 0; idx < 100; idx++) {
		ideas[idx].clear();
		ideas[idx].assign(target.ideas[idx]);
	}
	return *this;
}

void Brain::setIdeas(const std::string& idea) {
	for (int idx = 0; idx < 100; idx++) {
		ideas[idx].clear();
		ideas[idx].assign(idea);
	}
}
void Brain::setIdeas(const std::string& idea, int num) {
	ideas[num].clear();
	ideas[num].assign(idea);
}
std::string& Brain::getIdeas(int num) {
	return (ideas[num]);
}