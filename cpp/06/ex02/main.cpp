/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:01:27 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 10:08:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include "class.hpp"

int Base::seed = 0;

Base* generate(void) {
	Base*	ret;
	int		randomVal = 0;

	srand(time(NULL));
	randomVal = (std::rand() + Base::seed) % 3;
	if (randomVal == 0) {
		ret = new A;
	}
	else if (randomVal == 1) {
		ret = new B;
	}
	else {
		ret = new C;
	}
	Base::seed += 1;
	return (ret);
}

void	identify(Base * p) {
	if (dynamic_cast<A*>(p))
		p->printMyself();
	else if (dynamic_cast<B*>(p))
		p->printMyself();
	else
		p->printMyself();
}

void	identify(Base & p) {
	try {
		A& a = dynamic_cast<A&>(p);
		a.printMyself();
	} catch (std::bad_cast) {}
	try {
		B& b = dynamic_cast<B&>(p);
		b.printMyself();
	} catch (std::bad_cast) {}
	try {
		C& c = dynamic_cast<C&>(p);
		c.printMyself();
	} catch (std::bad_cast) {}
}

int main(void) {
	Base* randomPtr;

	for (int idx = 0; idx < 5; idx++) { 
		randomPtr = generate();
		identify(randomPtr);
		delete randomPtr;
		randomPtr = generate();
		identify(*randomPtr);
		delete randomPtr;
	}
	return (0);
}