/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:35:57 by haryu             #+#    #+#             */
/*   Updated: 2022/10/30 18:25:06 by haryu            ###   ########.fr       */
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
	class IndexOutOfRange : public std::exception {
		public:
			const char *	what() const throw() { return "size is over."; }
	};
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