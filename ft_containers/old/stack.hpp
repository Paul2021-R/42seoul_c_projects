/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:23:32 by haryu             #+#    #+#             */
/*   Updated: 2022/12/18 20:10:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#define FT_NOEXCEPT throw() 

namespace ft {

template <typename _T, typename _Container = vector<_T> >
class stack {
public:
typedef _Container container_type;
typedef typename container_type::value_type value_type;
typedef typename container_type::size_type size_type;

protected:
// vector<_T> c; 
container_type c;
// stack 라이브러리와 동일한 구조의 변수명으로 지정
// 자료구조인 컨테이너를 다른 것을 사용할 수도 있어서 설계 면에서는 container_type으로 구현해야 한다. 
// 하지만 사용 과정에서 vector 의 구조를 사용했다는 것을 알 수 있어야 하기에, 선언을 vector<_T> 로 해둠.

public:
//생성자
stack(const container_type& __c = container_type()) :c(__c) {}

//멤버 함수 
bool empty() const { return c.empty(); }
size_type size() const { return c.size(); }
value_type& top() { return c.back(); }
const value_type& top() const { return c.back(); }
void push(const value_type& val) { return c.push_back(val); }
void pop() { c.pop_back(); }

// 연산자들 
// 연산 과정에서 멤버 변수를 사용하므로 friend 키워드 사용이 필요함. 
// 구현 과정에서 다른 연산자도 적지 않아도, 두개로 구현하는데 어렵지 않다. 
template<typename T, typename Container>
friend bool operator ==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template<typename T, typename Container>
friend bool operator <(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

};

template<typename T, typename Container>
inline bool operator ==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return lhs.c == rhs.c;
}

template<typename T, typename Container>
inline bool operator !=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return !(lhs == rhs);
}

template<typename T, typename Container>
inline bool operator <(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return lhs.c < rhs.c;
}

template<typename T, typename Container>
inline bool operator >(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return rhs < lhs;
}

template<typename T, typename Container>
inline bool operator <=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return !(lhs > rhs);
}

template<typename T, typename Container>
inline bool operator >=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return !(lhs < rhs);
}

} // namespace ft stack 라이브러리 구현 완료

#endif