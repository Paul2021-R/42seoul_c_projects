/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:55:43 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 15:55:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
	int 				FixedPointVal;
	static const int	fractionalBit = 8;
public: 
	Fixed(void);
	Fixed(const Fixed& target);
	Fixed& operator=(const Fixed& target);
	~Fixed(void);
	int		getRawBits(void) const;
//	int		getfractionalBit(void) const;
	void	setRawBits(int const raw);
};

#endif 
