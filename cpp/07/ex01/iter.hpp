/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:56:16 by haryu             #+#    #+#             */
/*   Updated: 2022/10/29 14:20:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
# define iter_hpp

#include <iostream>

template <typename T>
void	iter(T* tPtr, size_t size, void (*fp)(T*)) {
	for(size_t idx = 0; idx < size; idx++) { fp(tPtr + idx); }
}

template <typename T>
void	printAddrVal(T* var) {
	std::cout << "Pointer : [" << &var << "] / Value : [" << *var << "]" << std::endl;
}

#endif