/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:06:48 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 21:25:02 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name("default"), gradeForSign(0), gradeForEx(0), blank(0) {}
Form::Form(const std::string& name, Grade sign, Grade ex);
Form::Form(const Form& target) {}
Form::~Form(void) {}
Form    &Form::operator=(const Form& target) {return *this;}

std::string getName(void) const {}
Grade   getGrade(const std::string& type) const {}

void    setSignGrade(Grade value) {}
void    setExecuteGrade(Grade value) {}

void    increaseGrade(int code) {}
void    decreaseGrade(int code) {}

void    beSigned(const Bureaucrat& Charger) {}

void    tryGradeIsOk(Grade& value) {
    if (value < 1)
        throw GradeTooHighException();
    else if (value > 150)
        throw GradeTooLowException();
    return ;
}

void    printExceptError(GradeTooHighException& e) {}
void    printExceptError(GradeTooLowException& e) {}

std::ostream& operator<<(std::ostream& s, const Form& target) {
    
}