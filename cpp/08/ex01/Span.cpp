/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:09:22 by haryu             #+#    #+#             */
/*   Updated: 2022/11/02 23:39:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): maxCapa(N) {
	curCapa = 0;
}

Span::Span(const Span& target) {
	maxCapa = target.maxCapa;
	curCapa = target.curCapa;
	vec.assign(target.vec.begin(), target.vec.end());
}

Span::~Span(void) {
	vec.clear();
}

Span& Span::operator=(const Span& target) {
	maxCapa = target.maxCapa;
	curCapa = target.curCapa;
	vec.assign(target.vec.begin(), target.vec.end());
	return *this;
}

bool	Span::findNumber(int val) {
	for (std::vector<int>::reverse_iterator rtr = vec.rbegin(); rtr != vec.rend(); ++rtr) {
		if (*rtr == val)
			return (true);
	}
	return (false);
}

void	Span::addNumber(int val) {
	try {
		if (curCapa == maxCapa)
			throw -1;
	} catch (...) {
		std::cout << "You add Numbers enough. Not anymore." << std::endl;
		return ;
	}
	try {
		if (findNumber(val)) 
			throw -1;
	} catch (...) {
		std::cout << "You already add Number : " << val << std::endl;
		return ;
	}
	vec.push_back(val);
	std::sort(vec.begin(), vec.end());
	curCapa++;
}

int		Span::shortestSpan(void) {
	if (curCapa < 2) {
		std::cout << "You need to add more numbers." << std::endl;
		return -1;
	}
	int	min = 0;
	int temp = 0;
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		if (min == 0) {
			min = *(itr + 1) - *(itr);
		}
		else {
			temp = *(itr + 1) - *(itr);
			if (temp < 0)
				break ;
			(min > temp) ? (min = temp) : (temp = 0);
		}
	}
	return (min);
}

int		Span::longestSpan(void) {
	if (curCapa < 2) {
		std::cout << "You need to add more numbers." << std::endl;
		return -1;
	}
	int	max = *(vec.end() - 1) - *(vec.begin());
	return (max);
}