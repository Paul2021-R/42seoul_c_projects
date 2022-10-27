/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:30:27 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:22:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// OCCF
RobotomyRequestForm::RobotomyRequestForm(void):
	Form("RobotomyRequest", 72, 45), target("none") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	Form("RobotomyRequest", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& target):
	Form("RobotomyRequest", 72, 45), target(target.target) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& target) {
	this->target = target.target;
	return *this;
}
/* ************************************************************************** */
// execute

void	RobotomyRequestForm::execute(const Bureaucrat & Executor) const {
	std::cout <<  "[Forms] " << target << " has been robotomized. : " << Executor.getName() << std::endl;
}
