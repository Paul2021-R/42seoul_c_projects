/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:22 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 15:56:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int 				FixedPointVal;
	static const int	fractionalBit = 8;
public: 
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);

	Fixed(const Fixed& target);

	Fixed& operator=(const Fixed& target);

	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& s, const Fixed& target); 
// 전역 변수로만 연산자 오버로딩이 가능하다. 

#endif 
