/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:14:21 by haryu             #+#    #+#             */
/*   Updated: 2022/12/21 23:19:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <functional>

namespace ft{

template <typename _T1, typename _T2>
struct pair{
typedef _T1 first_type;
typedef _T2 second_typ;

_T1 first;
_T2 second;

// 생성자 
pair () : first(), second() {}
template <typename _P1, typename _P2>
pair(const pair<_P1, _P2> & other) : 
	first(other.first), 
	second(other.second) {}
pair(const _T1 & t1, const _T2 & t2) :
	first(t1),
	second(t2) {}

//asign operator
pair& operator=(pair const & other) {
	first = other.first;
	second = other.second;
	return *this;
	}
};

template <typename _T1, typename _T2>
bool operator==(const pair<_T1, _T2> & lhs, const pair<_T1, _T2> & rhs) {
	return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

template <typename _T1, typename _T2>
bool operator!=(const pair<_T1, _T2> & lhs, const pair<_T1, _T2> & rhs) {
	return !(lhs == rhs);
}

template <typename _T1, typename _T2>
bool operator<(const pair<_T1, _T2> & lhs, const pair<_T1, _T2> & rhs) {
	return (lhs.first < rhs.first) && (lhs.second < rhs.second);
}

template <typename _T1, typename _T2>
bool operator>(const pair<_T1, _T2> & lhs, const pair<_T1, _T2> & rhs) {
	return (lhs.first > rhs.first) && (lhs.second > rhs.second);
}

template <typename _T1, typename _T2>
bool operator<=(const pair<_T1, _T2> & lhs, const pair<_T1, _T2> & rhs) {
	return !(lhs > rhs);
}

template <typename _T1, typename _T2>
bool operator>=(const pair<_T1, _T2> & lhs, const pair<_T1, _T2> & rhs) {
	return !(lhs < rhs);
}

template <typename _T1, typename _T2>
inline pair<_T1, _T2> make_pair(_T1 x, _T2 y) {
	return pair<_T1, _T2>(x, y);
}

template <typename T>
void swap(T & x, T & y) {
	T temp(x);
	x = y;
	y = temp;
}

template <typename pair>
struct select_first {
	typename pair::first_type &operator()(pair &__x) const { return __x.first; }
	const typename pair::first_type &operator()(const pair &__x) const { return __x.first; }
};

template <typename T>
struct identity {
	T &operator()(T & __x) const { return __x;}
	const T &operator()(const T & __x) const { return __x;}
};

} // ft utility pair, swap, first selector finished. 


#endif 