/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:36:40 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 15:36:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): 
	FixedPointVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& target){
	std::cout << "Copy constructor called" << std::endl;
	*this = target;
}

Fixed& Fixed::operator=(const Fixed& target) {
	std::cout << "Copy assignment operator called" << std::endl;
	FixedPointVal = target.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (FixedPointVal);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits memeber function called" << std::endl;
	FixedPointVal = raw;
}
/*
int Fixed::getfractionalBit(void) const {
	std::cout << "getfractionalBits member function called" << std::endl;
	std::cout << fractionalBit << std::endl;
	return (fractionalBit);
}*/
