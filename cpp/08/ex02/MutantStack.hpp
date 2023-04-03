/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:13:05 by haryu             #+#    #+#             */
/*   Updated: 2022/11/03 00:24:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_hpp
#define MutantStack_hpp

// 왜 고생해서 만들 필요가 없는가?
// stack 라이브러리 내에 container 자료타입은 deque로 구현되어 있다. 
// stack의 container c 는 protected로 상속받으면 접근이 가능한 구조.
// 즉, 상속 받음 + c에 접근하여 실제로 이미 iterate 한 속성을 끄집어내면, 그대로 사용이 가능함. 

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	//occf
	MutantStack(void): std::stack<T>() {}
	MutantStack(const MutantStack & rhs): std::stack<T>() {
		this->c = rhs.c;
	}
	MutantStack & operator=(const MutantStack & rhs)
	{
		if (this == &rhs)
			return (*this);
		this->c = rhs.c;
			return (*this);
	}
	~MutantStack(void) {}

	//iterator overriding
	iterator begin(void) { return (std::stack<T>::c.begin()); }
	const_iterator begin(void) const { return (std::stack<T>::c.begin()); }
	iterator end(void) { return (std::stack<T>::c.end()); }
	const_iterator end(void) const { return (std::stack<T>::c.end()); }
	reverse_iterator rbegin(void) { return (std::stack<T>::c.rbegin()); }
	const_reverse_iterator rbegin(void) const { return (std::stack<T>::c.rbegin()); }
	reverse_iterator rend(void) { return (std::stack<T>::c.rend()); }
	const_reverse_iterator rend(void) const { return (std::stack<T>::c.rend()); }

	//subscriptor
	T & operator[](int i) { return (std::stack<T>::c[i]); }		
};

template <typename T>
std::ostream & operator<<(std::ostream & o, const MutantStack<T> & rhs)
{
	typename MutantStack<T>::const_iterator it =  rhs.begin();
	while (it != rhs.end()) { o << *it++ << std::endl; }
	return (o);
}


#endif 