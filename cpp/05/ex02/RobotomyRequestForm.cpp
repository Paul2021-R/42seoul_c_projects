/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:30:27 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:02:46 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// OCCF
RobotomyRequestForm::RobotomyRequestForm(void):
	Form("RobotomyRequest", 72, 45), target("none") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	Form("RobotomyRequest", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& target):
	Form("RobotomyRequest", 72, 45), target(target.target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& target) {
	this->target = target.target;
	return *this;
}

/* ************************************************************************** */
// execute

void	RobotomyRequestForm::execute(const Bureaucrat & Executor) const {
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
	std::cout << "Drrrr...Drrrrr..Drrrr!!!!" << std::endl;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	if (dis(gen) == 0) {
		std::cout << "Robotomizing is failed : " << target << std::endl;
		return ;
	}
	Form *temp = (RobotomyRequestForm *)this;
	temp->beSigned(Executor);
	std::cout << target << "has been Robotomized : " << Executor.getName() << std::endl;
}

/* ************************************************************************** */
// exception

void	RobotomyRequestForm::tryGradeIsOk(const Bureaucrat& Executor) const {
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

const char* RobotomyRequestForm::GradeTooLowException::what() const throw() { return (EXCEPT_FAILED); }

void    RobotomyRequestForm::printExceptError(GradeTooLowException& e) const {
    std::cout << e.what() << *this << std::endl;
}