/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:19:08 by haryu             #+#    #+#             */
/*   Updated: 2022/12/21 15:53:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft{
template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
	while (first1 != last1) {
		if(!(*first1 == *first2))
			return false;
		++first1, ++first2;
	}
	return true;
}
template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
	while (first1 != last1) {
		if (!pred(*first1, *first2))
			return false;
		++first1, ++first2;
	}
	return true;
}
template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1) {
		if (first2 == last2 || *first1 > *first2)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1, ++first2;
	}
	return (first2 != last2);
}
template <typename InputIterator1, typename InputIterator2, typename Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare Comp) {
	while (first1 != last1) {
		if (first2 == last2 || Comp(*first2, *first1))
			return false;
		else if (Comp(*first1, *first2))
			return true;
		++first1, ++first2;
	}
	return (first2 != last2);
}
template <typename T>
const T& min(const T& x, const T& y) {
	return ((x < y) ? x : y);
}
} //name spcea 구현 완료


#endif