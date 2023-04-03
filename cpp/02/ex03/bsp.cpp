/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:03:04 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 19:53:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	checkMax(Point const a, Point const b, Point const c, Point const point) {
		Fixed	x;
		Fixed	y;

		x = Fixed::max(a.getPointX(), b.getPointX());
		x = Fixed::max(x, c.getPointX());

		y = Fixed::max(a.getPointY(), b.getPointY());
		y = Fixed::max(y, c.getPointY());

		if (x > point.getPointX() || y > point.getPointY())
			return (true);
		return (false);
}

bool	checkMin(Point const a, Point const b, Point const c, Point const point) {
		Fixed	x;
		Fixed	y;

		x = Fixed::min(a.getPointX(), b.getPointX());
		x = Fixed::min(x, c.getPointX());

		y = Fixed::min(a.getPointY(), b.getPointY());
		y = Fixed::min(y, c.getPointY());

		if (x < point.getPointX() || y < point.getPointY())
			return (true);
		return (false);
}

void	checkLine(Point const a, Point const b, int& crossCount, Point const point) {
	Fixed	crossedX;

	crossedX = ((a.getPointX() - b.getPointX()) * (point.getPointY() - a.getPointY()) / (b.getPointY() - a.getPointY()) + a.getPointX());
	if (point.getPointX() < crossedX)
		crossCount++;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	
	if (!checkMax(a, b, c, point) || !checkMin(a, b,c, point))
		return (false);
	
	int	crossCount = 0;

	checkLine(b, a, crossCount, point);
	checkLine(b, c, crossCount, point);
	checkLine(c, a, crossCount, point);
	if (crossCount % 2 == 1)
		return (true);
	return (false);

	// 1. get max, get min
	// 2. check max & min
	// 3. 삼각형 공식을 활용하여 선긋기 해보기

}
// point 를 받아온다. 
// 평면 상에서 좌표 a, b, c의 각 값을 기준으로 최소, 최대 x,y 좌표를 측정한다
// 만약 최대 이상~ 최소 이하 인 케이스의 경우 삼각형에 들어갈 가능성이 없다(1)
// 최대 이하, 최소 이상의 케이스라면, 선을 그어서, 점 point 에서 그은 직선과 선분 ab,ac, bc 가 만날 경우를 생각하고 그 점의 개수로 홀수번 겹치는지, 아니면 짝수번 겹치는지를 판단하면 된다. (2) 홀수 -> 내부에 있음 (2) 짝수 -> 외부에 있음
