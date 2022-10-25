/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:09:18 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:46:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	forms[0] = "shrubbery cration";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";
	forms[3].clear();
}

Intern::Intern(const Intern& target) {
	forms[0] = target.forms[0];
	forms[1] = target.forms[1];
	forms[2] = target.forms[2];
	forms[3].clear();
}

Intern::~Intern(void) {}

Intern& Intern::operator=(const Intern& target) { return (Intern &)target; }

Form*	Intern::makeForm(const std::string & type, const std::string & target){
	int 		idx = 0;
	Form		*ret;
	
	while (forms[idx].compare(type) != 0 && idx < 3) { idx++; }
	switch (idx) {
		case 0:
			ret = new ShrubberyCrationForm(target);
			break ;
		case 1:
			ret = new RobotomyRequestForm(target);
			break ;
		case 2:
			ret = new PresidentialPradonForm(target);
			break ;
		default:
			ret = NULL;
	}
	if (!ret) { std::cout << type << " is not exist" << std::endl; }
	else 
		std::cout << "Intern creates : " << forms[idx] << std::endl;
	return ret;
}