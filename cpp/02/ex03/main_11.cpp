/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_11.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:35:03 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 15:58:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>

int main(void) {
	std::string	temp;
	int	x;
	int	y;
	

	while(true) {
		std::cout << "Please type for Coordinate x for Point a: " << std::endl;
		getline(std::cin, temp);
		x = std::stoi(temp, nullptr, 10);
		std::cout << "Please type for Coordinate y for Point a: " << std::endl;
		getline(std::cin, temp);
		y = std::stoi(temp, nullptr, 10);
	
		Point	a(x, y);

		std::cout << "Please type for Coordinate x for Point b: " << std::endl;
		getline(std::cin, temp);
		x = std::stoi(temp, nullptr, 10);
		std::cout << "Please type for Coordinate y for Point b: " << std::endl;
		getline(std::cin, temp);
		y = std::stoi(temp, nullptr, 10);
	
		Point	b(x, y);

		std::cout << "Please type for Coordinate x for Point c: " << std::endl;
		getline(std::cin, temp);
		x = std::stoi(temp, nullptr, 10);
		std::cout << "Please type for Coordinate y for Point c: " << std::endl;
		getline(std::cin, temp);
		y = std::stoi(temp, nullptr, 10);
		
		Point	c(x, y);

		std::cout << "Please type for Coordinate x for Point Target: " << std::endl;
		getline(std::cin, temp);
		x = std::stoi(temp, nullptr, 10);
		std::cout << "Please type for Coordinate y for Point Target: " << std::endl;
		getline(std::cin, temp);
		y = std::stoi(temp, nullptr, 10);
	
		Point	target(x, y);

		std::cout << "This is your Triangle : " << std::endl;
		std::cout << "A( " << a.getPointX() << " , " << a.getPointY() << " )" << std::endl;
		std::cout << "B( " << b.getPointX() << " , " << b.getPointY() << " )" << std::endl;
		std::cout << "C( " << c.getPointX() << " , " << c.getPointY() << " )" << std::endl;

		std::cout << "This is Your Point for testing" << std::endl;
		std::cout << "Target( " << target.getPointX() << " , " << target.getPointY() << " )" << std::endl;

		if (bsp(a, b, c, target))
			std::cout << "\"target\" is in the triangle" << std::endl;
		else
			std::cout << "\"target\" is out of the triangle" << std::endl;
	}
	return 0;
}
