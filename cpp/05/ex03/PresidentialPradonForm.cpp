/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPradonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:54 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:47:37 by haryu            ###   ########.fr       */
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
	if (this->getSignOrNot() == true) {
		std::cout << "This form is already signed. : " << target << std::endl;
		return ;
	}
	try {
		tryGradeIsOk(Executor); 
	} catch (GradeTooLowException& e) {
		printExceptError(e);
		return ;
	}
	Form *temp = (PresidentialPradonForm *)this;
	temp->beSigned(Executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox. : " << Executor.getName() << std::endl;
}

/* ************************************************************************** */
// exception

void	PresidentialPradonForm::tryGradeIsOk(const Bureaucrat& Executor) const {
	if (getGrade(0) < Executor.getGrade()) {
		std::cout << "Not enough grade to sign this form. : " << Executor.getName() << std::endl;
		throw GradeTooLowException();
	}
	else if (getGrade(1) < Executor.getGrade()) {
		std::cout << "Not enough grade to execute this form. : " << Executor.getName() << std::endl;
		throw GradeTooLowException();
	}
	return ;
}

const char* PresidentialPradonForm::GradeTooLowException::what() const throw() { return (EXCEPT_FAILED); }

void    PresidentialPradonForm::printExceptError(GradeTooLowException& e) const {
    std::cout << e.what() << *this << std::endl;
}