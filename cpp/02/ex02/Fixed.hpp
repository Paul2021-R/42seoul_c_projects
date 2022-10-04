/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:56:54 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 15:56:55 by haryu            ###   ########.fr       */
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
	~Fixed(void);

	Fixed	operator+(const Fixed& val);
	Fixed	operator-(const Fixed& val);
	Fixed	operator*(const Fixed& val);
	Fixed	operator/(const Fixed& val);

	bool	operator<(const Fixed& val) const;
	bool	operator>(const Fixed& val) const;
	bool	operator<=(const Fixed& val) const;
	bool	operator>=(const Fixed& val) const;
	bool	operator==(const Fixed& val) const;
	bool	operator!=(const Fixed& val) const;

	Fixed& operator=(const Fixed& val);

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed& min(Fixed& valA, Fixed& valB) ;
	static Fixed const & min(const Fixed& valA, const Fixed& valB) ;
	static Fixed& max(Fixed& valA, Fixed& valB) ;
	static Fixed const & max(const Fixed& valA, const Fixed& valB) ;
};

std::ostream& operator<<(std::ostream& s, const Fixed& target); 
// 전역 변수로만 연산자 오버로딩이 가능하다. 

#endif 
