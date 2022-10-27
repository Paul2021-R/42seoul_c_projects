/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:38:26 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 07:30:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

convert::convert(void):
	alphabet(0),
	numInt(0),
	numFloat(0.0f),
	numDouble(0.0) {
	int i = 0;

	while (i < 4) {
		type[i] = 0;
	}
}

convert::convert(const char * str) {
	temp.assign(str);
	alphabet = convertToChar(str);
	numInt = convertToInt(str);
	numFloat = convertToFloat(str);
	numDouble = convertToDouble(str);

}

convert::convert(const convert& target):
	alphabet(target.alphabet),
	numInt(target.numInt),
	numFloat(target.numFloat),
	numDouble(target.numDouble) {
	int i = 0;

	while (i < 4) {
		type[i] = target.type[i];
	}
	temp.clear();
	temp.assign(target.temp);
}

convert::~convert(void) {}

convert& convert::operator=(const convert& target) {
	alphabet = target.alphabet;
	numInt = target.numInt;
	numFloat = target.numFloat;
	numDouble = target.numDouble;
	temp = target.temp;
	int i = 0;

	while (i < 4) {
		type[i] = target.type[i];
	}
	return *this;
}

char	convert::convertToChar(const char * str) {
	int			ret;
	double		checker;

	if (str[0] == '-' || str[0] == '+') {
		if (str[1] < '0' || str[1] > '9') {
			ret = 0;
			type[1] = 3;
		}
	}
	else if (str[0] < '0' || str[0] > '9') {
		ret = 0;
		type[1] = 4;
	}	
	try {
		checker = std::stod(temp);
	} catch (...) {
		ret = 0;
		type[0] = 4;
		return (ret);
	}
	ret = static_cast<int>(checker);
	if (ret < 33 || ret > 127)
		type[0] = 4;
	else
		type[0] = 1;
	return (static_cast<char>(ret));
}
int		convert::convertToInt(const char * str) {
	int ret;

	if (str[0] == '-' || str[0] == '+') {
		if (str[1] < '0' || str[1] > '9') {
			ret = 0;
			type[1] = 4;
		}
	}
	else if (str[0] < '0' || str[0] > '9') {
		ret = 0;
		type[1] = 4;
	}
	try {
		ret = std::stoi(temp);
	} catch (...) {
		ret = 0;
		type[1] = 4;
		return (ret);
	}
	type[1] = 1;
	return (ret);
}
float	convert::convertToFloat(const char * str) {
	float ret;
	std::string	infCheck(str);

	if (str[0] == '-' || str[0] == '+') {
		if (str[1] < '0' || str[1] > '9') {
			ret = 0.0;
			type[2] = 4;
		}
	}
	else if (str[0] < '0' || str[0] > '9') {
		ret = 0.0;
		type[2] = 4;
	}
	try {
		ret = std::stof(temp);
	} catch(...) {
		ret = 0.0;
		type[2] = 4;
		return (ret);
	}
	if (infCheck.compare("+inf") == 0 || infCheck.compare("inf") == 0)
		type[2] = 3;
	else if (infCheck.compare("-inf") == 0)
		type[2] = 2;
	else
		type[2] = 1;
	return (ret);
}
double	convert::convertToDouble(const char * str) {
	double ret;
	std::string	infCheck(str);

	if (str[0] == '-' || str[0] == '+') {
		if (str[1] < '0' || str[1] > '9') {
			ret = 0.0;
			type[3] = 4;
		}
	}
	else if (str[0] < '0' || str[0] > '9') {
		ret = 0.0;
		type[3] = 4;
	}
	try {
		ret = std::stod(temp);
	} catch(...) {
		type[3] = 4;
		return (ret);
	}
	if (infCheck.compare("+inf") == 0 || infCheck.compare("inf") == 0)
		type[3] = 3;
	else if (infCheck.compare("-inf") == 0)
		type[3] = 2;
	else
		type[3] = 1;
	return (ret);
}

void	convert::printChar(void) const {
	std::cout << "char: ";
	switch (type[0])
	{
	case 0:
		std::cout << "no input";
		break;
	case 1:
		if (alphabet > 0 && alphabet < 127)
			std::cout << "\'" << alphabet << "\'";
		else
			std::cout << ND;
		break;
	case 2:
		std::cout << ND;
		break ;
	case 3:
		std::cout << ND;
	case 4:
		std::cout << ND;
		break;
	default:
		std::cout << "error happen.";
	}
	std::cout << std::endl;
}
void	convert::printInt(void) const {
	std::cout << "int: ";
	switch (type[1])
	{
	case 0:
		std::cout << "no input";
		break;
	case 1:
		std::cout << numInt;
		break;
	case 2:
		std::cout << "-" << IN;
		break;
	case 3:
		std::cout << "+" << IN;
		break;
	case 4:
		std::cout << NAN1;
		break;
	default:
		std::cout << "error happen.";
	}
	std::cout << std::endl;	
}
void	convert::printFloat(void) const {
	std::cout << "float: ";
	float	temp = numFloat;
	switch (type[2])
	{
	case 0:
		std::cout << "no input";
		break;
	case 1:
		if (temp - static_cast<int>(temp) == 0) 
			std::cout << numFloat << ".0" << "f";
		else
			std::cout << numFloat << "f";
		break;
	case 2:
		std::cout << "-" << IN << "f";
		break;
	case 3:
		std::cout << "+" << IN << "f";
		break;
	case 4:
		std::cout << NAN2 << "f";
		break;
	default:
		std::cout << "error happen.";
	}
	std::cout << std::endl;
}
void	convert::printDouble(void) const {
	std::cout << "double: ";
	double	temp = numDouble;
	switch (type[3])
	{
	case 0:
		std::cout << "no input";
		break;
	case 1:
		if (temp - static_cast<int>(temp) == 0)
			std::cout << numDouble << ".0";
		else
			std::cout << numDouble;
		break;
	case 2:
		std::cout << "-" << IN;
		break;
	case 3:
		std::cout << "+" << IN;
		break;
	case 4:
		std::cout << NAN2;
		break;
	default:
		std::cout << "error happen.";
	}
}

std::ostream&	operator<<(std::ostream& s, const convert& target) {
	target.printChar();
	target.printInt();
	target.printFloat();
	target.printDouble();
	return s;
}
