/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:35:57 by haryu             #+#    #+#             */
/*   Updated: 2022/10/29 21:24:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_hpp
# define Array_hpp

# include <iostream>
# include <stdexcept>

template<typename T>
class Array {
private:
	unsigned int len;
	unsigned int capacity;
public:
	T*	array;
	Array(void);
	Array(unsigned int n);
	Array(const Array& target);
	~Array(void);
	Array&	operator=(const Array& target);
	T&	operator[](unsigned int idx) const;
	/**
	 * @brief get size for array
	 * 
	 * @return unsigned int 
	 */
	unsigned int size(void) const; 
};

#include "Array.tpp"
#endif