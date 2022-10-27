/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:06:48 by haryu             #+#    #+#             */
/*   Updated: 2022/10/27 18:18:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
// OCCF
Form::Form(void): name("default"), gradeForSign(0), gradeForEx(0), blank(0) {}
Form::Form(const std::string& name, Grade sign, Grade ex): 
	name(name), 
	gradeForSign(sign), 
	gradeForEx(ex) {
	try {
		tryGradeIsOk(gradeForSign);
		tryGradeIsOk(gradeForEx);
	} catch (GradeTooHighException& e) {
		printExceptError(e);
	} catch (GradeTooLowException& e) {
		printExceptError(e);
	}
	blank = false;
}
Form::Form(const Form& target):
	name(target.getName()),
	gradeForSign(target.getGrade(0)),
	gradeForEx(target.getGrade(1)),
	blank(target.blank) {
}
Form::~Form(void) {}
Form    &Form::operator=(const Form& target) {
	int	condition = 0;

	condition = name.compare(target.getName());
	condition = this->getGrade(0) - target.getGrade(0);
	condition = this->getGrade(1) - target.getGrade(1);
	if (condition == 0)
		blank = target.blank;
	else
		std::cout << "= operator can't work." << std::endl;
	return *this;
}

/* ************************************************************************** */
// getter
std::string Form::getName(void) const { return name; }

Grade   Form::getGrade(char var) const {
	if (var == 0)
		return (gradeForSign);
	else if (var == 1)
		return (gradeForEx);
	return (0);
}

bool	Form::getSignOrNot(void) const { return blank; }

/* ************************************************************************** */

void    Form::beSigned(const Bureaucrat& Charger) {
	try {
		if (Charger.getGrade() > gradeForSign)
			throw GradeTooLowException();
	} catch (GradeTooLowException& e) {
		printExceptError(e);
		return ;
	}
	blank = true;
	return ;
}

/* ************************************************************************** */
// internal Functions for operating

void    Form::tryGradeIsOk(const Grade& value) {
    if (value < 1)
        throw GradeTooHighException();
    else if (value > 150)
        throw GradeTooLowException();
    return ;
}

void    Form::printExceptError(GradeTooHighException& e) {
    std::cout << e.what() << std::endl;
	std::cout << *this << std::endl;
}
void    Form::printExceptError(GradeTooLowException& e) {
    std::cout << e.what() << std::endl;
	std::cout << *this << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() { return (EXCEPT_FAILED); }

const char* Form::GradeTooLowException::what() const throw() { return (EXCEPT_FAILED); }

/* ************************************************************************** */
// operator overriding

std::ostream& operator<<(std::ostream& s, const Form& target) {
    std::cout << target.getName() << " [Grade for Sign : " << target.getGrade(0) << " / Grade for Execute : " << target.getGrade(1) << "] ";
    return s;
}


