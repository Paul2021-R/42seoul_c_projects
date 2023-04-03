/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:44:12 by haryu             #+#    #+#             */
/*   Updated: 2022/10/29 13:55:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void) {
	int a = 2; 
	int b = 3; 
	::swap( a, b ); 
	std::cout << "a = " << a << ", b = " << b << std::endl; 
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; 
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl; 
	std::string c = "chaine1"; std::string d = "chaine2"; 
	::swap(c, d); 
	std::cout << "c = " << c << ", d = " << d << std::endl; 
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl; 
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl; 
	return 0; 
}