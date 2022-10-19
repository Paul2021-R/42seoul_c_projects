/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:28:55 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 13:25:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade setting Failed."); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade setting Failed."); }

void    Bureaucrat::tryGradeIsOk(void) {
    if (grade < 0)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    return ;
}

Bureaucrat::Bureaucrat(void): name("defualt"), grade(0) {}

Bureaucrat::Bureaucrat(const std::string& name, Grade grade): name(name), grade(grade) {
    try {
        tryGradeIsOk();
    } catch (GradeTooHighException& e) {
        std::cout << name << " : Grade setting is too high." << std::endl;
        std::cout << e.what() << std::endl;
    } catch (GradeTooLowException& e) {
        std::cout << name << " : Grade setting is too low." << std::endl;
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& target): name(target.name), grade(target.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&         Bureaucrat::operator=(const Bureaucrat& target) {
    grade = target.grade;
    return *this;
}

std::string		        	Bureaucrat::getName(void) const { return name; }
Grade	    				Bureaucrat::getGrade(void) const { return grade; }

void						Bureaucrat::setGrade(Grade value) {
    Grade temp = grade;
    grade = value;
    try {
        tryGradeIsOk();
    } catch (GradeTooHighException & e) {
        std::cout << name << " : Grade setting is too high." << std::endl;
        std::cout << e.what() << std::endl;
        grade = 0;
        return ;
    } catch (GradeTooLowException & e) {
        std::cout << name << " : Grade setting is too low." << std::endl;
        std::cout << e.what() << std::endl;
        grade = 150;
        return ;
    }
    std::cout << name << " : Grade is changed : " << temp << " => " << value << std::endl;
}

void						Bureaucrat::increaseGrade(Grade value){ setGrade(getGrade() - value); }
void						Bureaucrat::increaseGrade(void){ setGrade(getGrade() - 1); }
void						Bureaucrat::decreaseGrade(Grade value){ setGrade(getGrade() + value); }
void						Bureaucrat::decreaseGrade(void){ setGrade(getGrade() + 1); }

std::ostream& operator<<(std::ostream& s, const Bureaucrat& target) {
    std::cout << target.getName() << " [ " << target.getGrade() << " ] ";
    return s;
}