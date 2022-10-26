/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:06:48 by haryu             #+#    #+#             */
/*   Updated: 2022/10/26 18:01:57 by haryu            ###   ########.fr       */
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
	gradeForSign(target.getGrade("sign")),
	gradeForEx(target.getGrade("execute")),
	blank(target.blank) {
}
Form::~Form(void) {}
Form    &Form::operator=(const Form& target) {
	Form* temp = new Form(target);
	return *temp; 
}

/* ************************************************************************** */
// getter
std::string Form::getName(void) const { return name; }

Grade   Form::getGrade(const std::string& type) const {
	if (!type.compare("sign"))
		return (gradeForSign);
	else if (!type.compare("execute"))
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
    std::cout << target.getName() << " [Grade for Sign : " << target.getGrade("sign") << " / Grade for Execute : " << target.getGrade("execute") << "] ";
    return s;
}


