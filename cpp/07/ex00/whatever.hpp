/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:45:23 by haryu             #+#    #+#             */
/*   Updated: 2022/10/29 14:27:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_hpp
# define whatever_hpp

template <typename T>
void swap(T& a, T& b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T&	min(T& a, T& b) {
	return a > b ? b : a;
}

template <typename T>
T& max(T& a, T& b) {
	return a > b ? a : b;
}

#endif