/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:34:42 by haryu             #+#    #+#             */
/*   Updated: 2022/09/30 16:06:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point 
{
private:
	Fixed const posX;
	Fixed const posY;
public:
	Point(void);
	Point(Fixed const x, Fixed const y);
	Point(Point const &target);
	~Point(void);
	Point	&operator=(Point &target);
	Fixed getPointX(void) const;
	Fixed getPointY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
// point 를 받아온다. 
// 평면 상에서 좌표 a, b, c의 각 값을 기준으로 최소, 최대 x,y 좌표를 측정한다
// 만약 최대 이상~ 최소 이하 인 케이스의 경우 삼각형에 들어갈 가능성이 없다(1)
// 최대 이하, 최소 이상의 케이스라면, 선을 그어서, 점 point 에서 그은 직선과 선분 ab,ac, bc 가 만날 경우를 생각하고 그 점의 개수로 홀수번 겹치는지, 아니면 짝수번 겹치는지를 판단하면 된다. (2) 홀수 -> 내부에 있음 (2) 짝수 -> 외부에 있음

#endif
