/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:07 by haryu             #+#    #+#             */
/*   Updated: 2022/09/30 16:36:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : 
	posX(0),
	posY(0) {}

Point::Point(Fixed const x, Fixed const y) :
	posX(x),
	posY(y) {}

Point::Point(Point const &target) : 
	posX(target.getPointX()),
	posY(target.getPointY()) {}

Point::~Point(void) {}

Point&	Point::operator=(Point &target) {
	return (target);
}

Fixed Point::getPointX(void) const {
	return (this->posX);
}
Fixed Point::getPointY(void) const {
	return (this->posY);
}
