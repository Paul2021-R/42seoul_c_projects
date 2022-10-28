/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:01:27 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 17:55:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include "class.hpp"

// 예외처리의 기술을 활용하는 방법이다. 문제는 bad_cast 라는 아주 좋은 물건이 typeinfo 헤더에 포함되서 사용이 불가능하다는 점이다. 따라서, 이를 개선하고자 excetion 발생시 뭐든 catch 하는 옵션으로 수정하자 정상 작동됨. 

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
	} catch (...) {}
	try {
		B& b = dynamic_cast<B&>(p);
		b.printMyself();
	} catch (...) {}
	try {
		C& c = dynamic_cast<C&>(p);
		c.printMyself();
	} catch (...) {}
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