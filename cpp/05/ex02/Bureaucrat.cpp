/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:28:55 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:39:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* ************************************************************************** */
// OCCF

Bureaucrat::Bureaucrat(void): name("defualt"), grade(0) {}

Bureaucrat::Bureaucrat(const std::string& name, Grade grade): name(name), grade(grade) {
    try {
        tryGradeIsOk();
    } catch (GradeTooHighException& e) {
        printExceptError(e);
    } catch (GradeTooLowException& e) {
        printExceptError(e);
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& target): name(target.name), grade(target.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& target) {
    grade = target.grade;
    return *this;
}

/* ************************************************************************** */
//getter

std::string Bureaucrat::getName(void) const { return name; }

Grade   Bureaucrat::getGrade(void) const { return grade; }


/* ************************************************************************** */
//setter

void    Bureaucrat::increaseGrade(void){ setGrade(getGrade() - 1); }

void	Bureaucrat::decreaseGrade(void){ setGrade(getGrade() + 1); }

void    Bureaucrat::setGrade(Grade value) {
    Grade temp = grade;
    grade = value;
    try {
        tryGradeIsOk();
    } catch (GradeTooHighException & e) {
        printExceptError(e);
        grade = 1;
        return ;
    } catch (GradeTooLowException & e) {
        printExceptError(e);
        grade = 150;
        return ;
    }
    std::cout << "[Bureaucrat] " << GRADE_CHANGE << name << " : " << temp << " => " << grade << std::endl;
}

/* ************************************************************************** */
// required functions

void	Bureaucrat::signForm(Form & paper) {
	paper.beSigned(*this);
	if (paper.getSignOrNot() == true) {
		std::cout << "[Bureaucrat] " << name << " signed : " << paper.getName() << std::endl;
	}
	else {
		std::cout << "[Bureaucrat] " << name << " couldn't sign : " << paper.getName() << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm(Form const & form) {
	if (form.getGrade(0) >= getGrade() && form.getGrade(1) >= getGrade())
		form.execute(*this);
		std::cout << "[Bureaucrat] " << *this << " excuted " << form << std::endl;
	return ;
}

void	Bureaucrat::signAndExecute(Form & paper) {
	if (paper.getSignOrNot() == true) {
		std::cout << "[Bureaucrat] " << name << " couldn't sign : " << paper.getName() << " is already signed." << std::endl;
		return ;
	}
	signForm(paper);
	if (paper.getSignOrNot() == false)
		return ;
	if (paper.getGrade(1) < getGrade()) {
		std::cout << "[Bureaucrat] " << *this << " couldn't have enough grade for execution. " << std::endl;;
		std::cout << "[" << paper.getName() << "] " << paper << std::endl;
		paper.setBlank();
		return ;	
	}
	executeForm(paper);
}

/* ************************************************************************** */
// internal functions for operating class 

void    Bureaucrat::tryGradeIsOk(void) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    return ;
}

void    Bureaucrat::printExceptError(GradeTooHighException& e) {
    std::cout << e.what() << name << std::endl;
    std::cout << GRADE_HIGH << name << std::endl;
}
void    Bureaucrat::printExceptError(GradeTooLowException& e) {
    std::cout << e.what() << name << std::endl;
    std::cout << GRADE_LOW  << name << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return (EXCEPT_FAILED); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return (EXCEPT_FAILED); }

/* ************************************************************************** */
// operator overriding

std::ostream&   operator<<(std::ostream& s, const Bureaucrat& target) {
    std::cout << target.getName() << " [ " << target.getGrade() << " ] ";
    return s;
}
