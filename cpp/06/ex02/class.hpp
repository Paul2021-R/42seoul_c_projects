/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:05:18 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 09:54:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Derived_hpp
# define Derived_hpp

# include "base.hpp"
# include <iostream>

class A : public Base {
public:
	~A(void) {}
	void printMyself(void) {
		std::cout << "This is [A]" << std::endl;
	}
};

class B : public Base {
public:
	~B(void) {}
	void printMyself(void) {
		std::cout << "This is [B]" << std::endl;
	}
};

class C : public Base {
public:
	~C(void) {}
	void printMyself(void) {
		std::cout << "This is [C]" << std::endl;
	}
};
#endif