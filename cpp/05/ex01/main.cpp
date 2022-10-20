/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:21:09 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 01:28:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat test("haryu", 1);
	Form* form = new Form("test1", 2, 3);

	std::cout << "get Name : " << form->getName() << std::endl;
	std::cout << "get Grade : " << "Sign Grade : " << form->getGrade("sign") << " / Execute Grade : " << form->getGrade("execute") << std::endl;

	std::cout << test << std::endl;
	std::cout << *form << std::endl;

	test.decreaseGrade();
	test.decreaseGrade();
	test.decreaseGrade();

	test.signForm(*form);

	test.increaseGrade();
	test.increaseGrade();
	test.increaseGrade();
	test.increaseGrade();

	test.signForm(*form);
	test.signForm(*form);

	delete form;
	return 0;
}