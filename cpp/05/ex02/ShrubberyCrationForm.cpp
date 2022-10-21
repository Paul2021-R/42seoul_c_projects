/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:42 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 09:39:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCrationForm.hpp"

ShrubberyCrationForm::ShrubberyCrationForm(void):
	Form() {}

ShrubberyCrationForm::ShrubberyCrationForm(const ShrubberyCrationForm& target):
	Form(target.getName(), target.getGrade("sign"), target.getGrade("execute")) {}

ShrubberyCrationForm::~ShrubberyCrationForm(void) {}

ShrubberyCrationForm& ShrubberyCrationForm::operator=(const ShrubberyCrationForm& target) { return *this; }

void	ShrubberyCrationForm::execute(const Bureaucrat & Excutor) const {
	if (getGrade("sign") >= Excutor.getGrade())
}