/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:06:48 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:43:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// OCCF
Form::Form(void): name("default"), gradeForSign(1), gradeForEx(1), blank(0) {}
Form::Form(const std::string& name, Grade sign, Grade ex): 
	name(name), 
	gradeForSign(sign), 
	gradeForEx(ex),
	blank(false)	
 {
	try {
		tryGradeIsOk(gradeForSign);
		tryGradeIsOk(gradeForEx);
	} catch (GradeTooHighException& e) {
		printExceptError(e);
	} catch (GradeTooLowException& e) {
		printExceptError(e);
	}
}
Form::Form(const Form& target):
	name(target.getName()),
	gradeForSign(target.getGrade(0)),
	gradeForEx(target.getGrade(1)),
	blank(target.blank) {
}
Form::~Form(void) {}
Form&	Form::operator=(const Form& target) {
	int	condition = 0;

	condition = name.compare(target.getName());
	condition = this->getGrade(0) - target.getGrade(0);
	condition = this->getGrade(1) - target.getGrade(1);
	if (condition == 0) {
		blank = target.blank;
		std::cout << "[Form]" << "= operator worked." << std::endl;
	}
	else
		std::cout << "[Form]" << "= operator can't work." << std::endl;
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

bool	Form::getRandomVal(void) {
	bool	ret;

	srand(time(NULL));
	ret = std::rand() % 2;
	std::cout << "[Forms] " << "Drrrr...Drrrrr..Drrrr!!!!" << std::endl;
	if (ret == false)
		std::cout << "[Forms] " << "Robotomizing is failed : " << std::endl;
	return ret;
}

void	Form::setBlank(void) {
	blank = false;
}

/* ************************************************************************** */

void    Form::beSigned(const Bureaucrat& Charger) {
	if (Charger.getGrade() > gradeForSign){
		std::cout << "[Forms] Grade is not enough to sign it." << std::endl;
		return ;
	}
	blank = true;
	if (name.compare("RobotomyRequest") == 0)
		blank = getRandomVal();
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

void    Form::printExceptError(GradeTooHighException& e) const {
	std::cout << e.what() << *this << std::endl;
}
void    Form::printExceptError(GradeTooLowException& e) const {
	std::cout << e.what() << *this << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() { return (EXCEPT_FAILED); }

const char* Form::GradeTooLowException::what() const throw() { return (EXCEPT_FAILED); }

/* ************************************************************************** */
// operator overriding

std::ostream& operator<<(std::ostream& s, const Form& target) {
    std::cout << target.getName() << " [Grade for Sign : " << target.getGrade(0) << " / Grade for Execute : " << target.getGrade(1) << "] ";
    return s;
}


