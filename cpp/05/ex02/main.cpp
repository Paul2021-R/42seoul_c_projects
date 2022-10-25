/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:26:57 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:02:09 by haryu            ###   ########.fr       */
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

	test1.execute(haryu);
	haryu.increaseGrade();
	test1.execute(haryu);
	std::cout << "Signed : " << test1.getSignOrNot() << std::endl;

	Bureaucrat another_haryu("another Haryu", 1);
	test1.execute(another_haryu);
	std::cout << "Signed : " << test1.getSignOrNot() << std::endl;
	test1.execute(haryu);

	std::cout << "==========================Robotomy Request Form============================" << std::endl;
	RobotomyRequestForm test2("GUNDAM");
	
	test2.execute(haryu);
	while (true) {
		test2.execute(another_haryu);
		if (test2.getSignOrNot() == true)
			break ;
	}
	test2.execute(another_haryu);

	std::cout << "==========================Presidential Pardon Form============================" << std::endl;

	PresidentialPradonForm test3("YUUUUUUUUUUU");
	test3.execute(haryu);
	std::cout << "Signed : " << test3.getSignOrNot() << std::endl;
	test3.execute(another_haryu);
	std::cout << "Signed : " << test3.getSignOrNot() << std::endl;
	test3.execute(another_haryu);
}