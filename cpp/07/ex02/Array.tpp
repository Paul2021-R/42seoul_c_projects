/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:40:13 by haryu             #+#    #+#             */
/*   Updated: 2022/10/30 18:24:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) {
	array = new T[1];
	len = 1;
	capacity = 1;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	array = new T[n];

	for (unsigned int idx = 0; idx < n; idx++) { array[idx] = 0; }
	len = n;
	capacity = n;
}

template <typename T>
Array<T>::Array(const Array& target) {
	array = new T[target.size()];
	len = target.len;
	capacity = target.capacity;
	for (unsigned int idx = 0; idx < capacity; idx++) {
		array[idx] = target.array[idx];
	}
}

template <typename T>
Array<T>::~Array(void) {
	delete [] array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& target) {
	if (capacity != 0)
		delete [] array;
	array = new T [target.capacity];
	len = target.len;
	capacity = target.capacity;
	for (unsigned int idx = 0; idx < capacity; idx++) {
		array[idx] = target.array[idx];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) const {
	if (idx >= len)
		throw IndexOutOfRange();
	else if (idx < 0)
		throw IndexOutOfRange();
	return (array[idx]);
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return (len);
}
