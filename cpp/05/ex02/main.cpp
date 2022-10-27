/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:26:57 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:46:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCrationForm.hpp"
#include "PresidentialPradonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
	std::cout << "==========================Shrubbery Cration Form============================" << std::endl;
	Bureaucrat haryu("haryu", 146);
	ShrubberyCrationForm test1("home");
	std::cout << "Signed : " << test1.getSignOrNot() << std::endl;
	haryu.signAndExecute(test1);
	haryu.increaseGrade();
	haryu.signAndExecute(test1);
	std::cout << "Signed : " << test1.getSignOrNot() << std::endl;

	Bureaucrat another_haryu("another Haryu", 1);
	another_haryu.signAndExecute(test1);
	std::cout << "Signed : " << test1.getSignOrNot() << std::endl;
	haryu.signAndExecute(test1);

	std::cout << "==========================Robotomy Request Form============================" << std::endl;
	RobotomyRequestForm test2("GUNDAM");
	
	haryu.signAndExecute(test2);
	while (true) {
		another_haryu.signAndExecute(test2);
		if (test2.getSignOrNot() == true)
			break ;
	}
	another_haryu.signAndExecute(test2);

	std::cout << "==========================Presidential Pardon Form============================" << std::endl;

	PresidentialPradonForm test3("YUUUUUUUUUUU");
	haryu.signAndExecute(test3);
	std::cout << "Signed : " << test3.getSignOrNot() << std::endl;
	another_haryu.signAndExecute(test3);
	std::cout << "Signed : " << test3.getSignOrNot() << std::endl;
	another_haryu.signAndExecute(test3);
	
	std::cout << "==========================Assign Operator problem============================" << std::endl;

	Form *test4;
	Form *test5;
	Form *test6;
	ShrubberyCrationForm test7;
	test4 = &test1;
	test5 = &test7;
	test6 = &test2;

	std::cout << *test5 << test5->getSignOrNot() << std::endl;
	*test5 = *test4;
	std::cout << *test5 << test5->getSignOrNot() << std::endl;
	*test5 = *test6;
	std::cout << *test5 << test5->getSignOrNot() << std::endl;
}