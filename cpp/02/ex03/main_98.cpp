/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_98.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:58:48 by haryu             #+#    #+#             */
/*   Updated: 2022/10/05 15:17:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 30);
	Point	in(10, 15);
	Point	out(30, 50);

	std::cout << "Point \"in\" created at x-" << in.getPointX() << " y-" << in.getPointY() << std::endl;
	std::cout << "Point \"out\" created at x-" << out.getPointX() << " y-" << out.getPointY() << std::endl;
	if (bsp(a, b, c, in))
		std::cout << "\"in\" is in the triangle" << std::endl;
	else
		std::cout << "\"in\" is out of the triangle" << std::endl;
	if (bsp(a, b, c, out))
		std::cout << "\"out\" is in the triangle" << std::endl;
	else
		std::cout << "\"out\" is out of the triangle" << std::endl;
	return 0;
}
