/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:27:15 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 07:55:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef convert_hpp
# define convert_hpp

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>
# include <limits>

# define ND "Non displayable"
# define NAN1 "impossible"
# define NAN2 "nan"
# define IN "inf"
# define FL "f"

/**
 * @brief 저장할 값들을 넣어두는 클래스
 * 
 */
class convert {
private:
	char		alphabet;
	int			numInt;
	float		numFloat;
	double		numDouble;
	std::string	temp;
	/**
	 * @brief 0 : 값이 없는 상태, 1 : 출력 가능 상태, 2 : -inf, 3: +inf, 4: nan
	 * 
	 */
	int		type[4];
	char	convertToChar(const char * str);
	int		convertToInt(const char * str);
	float	convertToFloat(const char * str);
	double	convertToDouble(const char * str);
public:
									convert(void);
									convert(const char * str);
									convert(const convert& target);
									~convert(void);
	convert&						operator=(const convert& target);
	void							printChar(void) const ;
	void							printInt(void) const ;
	void							printFloat(void) const ;
	void							printDouble(void) const ;
};

std::ostream& operator<<(std::ostream& s, const convert& target);

#endif