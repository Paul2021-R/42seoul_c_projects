/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:09:24 by haryu             #+#    #+#             */
/*   Updated: 2022/11/02 22:51:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_hpp
# define Span_hpp

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
private:
	unsigned int		maxCapa;
	unsigned int		curCapa;
	std::vector<int>	vec;
public:
						Span(unsigned int N);
						Span(const Span& target);
						~Span(void);
	Span&				operator=(const Span& target);

	std::vector<int>&	getVec(void) { return vec; }
	bool				findNumber(int val);

	void 				addNumber(int val);
	int					shortestSpan(void);
	int					longestSpan(void);
};
#endif