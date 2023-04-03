/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPradonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:54 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:41:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPradonForm.hpp"

// OCCF
PresidentialPradonForm::PresidentialPradonForm(void):
	Form("PresidentialPardon", 25, 5), target("none") {}

PresidentialPradonForm::PresidentialPradonForm(const std::string& target): 
	Form("PresidentialPardon", 25, 5), target(target) {}

PresidentialPradonForm::PresidentialPradonForm(const PresidentialPradonForm& target):
	Form("PresidentialPardon", 25, 5), target(target.target) {} 

PresidentialPradonForm::~PresidentialPradonForm(void) {}

PresidentialPradonForm	&PresidentialPradonForm::operator=(const PresidentialPradonForm& target) {
	this->target = target.target;
	return *this;
}

/* ************************************************************************** */
// execute

void	PresidentialPradonForm::execute(const Bureaucrat & Executor) const {
	std::cout <<"[Forms] " << target << " has been pardoned by Zaphod Beeblebrox. : " << Executor.getName() << std::endl;
}
