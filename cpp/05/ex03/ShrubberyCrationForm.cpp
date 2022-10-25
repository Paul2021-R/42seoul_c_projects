/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:42 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:48:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCrationForm.hpp"

// OCCF
ShrubberyCrationForm::ShrubberyCrationForm(void):
	Form("ShrubberyCration", 145, 137), target("none") {}
ShrubberyCrationForm::ShrubberyCrationForm(const std::string& target):
	Form("ShrubberyCration", 145, 137), target(target) {
}
ShrubberyCrationForm::ShrubberyCrationForm(const ShrubberyCrationForm& target):
	Form(target.getName(), target.getGrade(0), target.getGrade(1)), target(target.target) {}

ShrubberyCrationForm::~ShrubberyCrationForm(void) {}

ShrubberyCrationForm& ShrubberyCrationForm::operator=(const ShrubberyCrationForm& target) {
	this->target = target.target;
	return *this;
}

/* ************************************************************************** */
// execute

void	ShrubberyCrationForm::execute(const Bureaucrat & Executor) const {
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
	Form *temp = (ShrubberyCrationForm *)this;
	temp->beSigned(Executor);
	makeShruberry(Executor);
}

void	ShrubberyCrationForm::makeShruberry(const Bureaucrat & Executor) const {
	std::ofstream	berry;
	std::ifstream	tree;
	std::string		filename = target;

	filename.append("_shrubbery");
	berry.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

	tree.open("ascii-art.txt", std::ifstream::in);
	berry << filename;
	while (true) {
		char *buffer = new char [101];
		tree.read(buffer, 100);
		buffer[100] = 0;
		berry << buffer;
		delete[] buffer;
		if (tree.eof())
			break ;
	}
	tree.close();
	berry.close();
	std::cout << "Making Shrubbery cration is completed. : " << Executor.getName() << std::endl;
}

/* ************************************************************************** */
// exception

void	ShrubberyCrationForm::tryGradeIsOk(const Bureaucrat& Executor) const {
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

const char* ShrubberyCrationForm::GradeTooLowException::what() const throw() { return (EXCEPT_FAILED); }

void    ShrubberyCrationForm::printExceptError(GradeTooLowException& e) const {
    std::cout << e.what() << *this << std::endl;
}