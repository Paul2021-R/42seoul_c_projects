/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:26:57 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:46:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCrationForm.hpp"
#include "PresidentialPradonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern	someRandomIntern;
	Form *	task;
	std::string target("Hello World!");
	Bureaucrat toolow("sample1", 150);
	Bureaucrat good("sample2", 1);

	std::cout << "==========================Shrubbery Cration Form============================" << std::endl;
	task = someRandomIntern.makeForm("shrubbery cration", target);
	task->execute(toolow);
	std::cout << "Signed : " << task->getSignOrNot() << std::endl;
	task->execute(good);
	std::cout << "Signed : " << task->getSignOrNot() << std::endl;
	delete task;

	std::cout << "==========================Robotomy Request Form============================" << std::endl;
	task = someRandomIntern.makeForm("robotomy request", target);
	task->execute(toolow);
	std::cout << "Signed : " << task->getSignOrNot() << std::endl;
	task->execute(good);
	task->execute(good);
	task->execute(good);
	task->execute(good);
	std::cout << "Signed : " << task->getSignOrNot() << std::endl;
	delete task;

	std::cout << "==========================Presidential Pardon Form============================" << std::endl;
	task = someRandomIntern.makeForm("presidential pardon", target);
	task->execute(toolow);
	std::cout << "Signed : " << task->getSignOrNot() << std::endl;
	task->execute(good);
	std::cout << "Signed : " << task->getSignOrNot() << std::endl;
	delete task;

	std::cout << "==========================Error Form============================" << std::endl;
	task = someRandomIntern.makeForm("error form", target);
}