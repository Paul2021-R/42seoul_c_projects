/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:45:14 by haryu             #+#    #+#             */
/*   Updated: 2022/11/02 23:00:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template<typename T>
void printVector(std::vector<T>& vec) {
	std::cout << "벡터 값 : [ ";
	int idx = 0;
	for(typename std::vector<T>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr) {
		std::cout << "(" << idx << ")번 : "<< *itr << " / ";
		idx++;
	}
	std::cout << " ]" << std::endl;
}

int main() 
{ 
	Span sp = Span(5); 
	sp.addNumber(5); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(20); 
	printVector(sp.getVec());
	//3 5 9 11 17
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl; 

	std::cout << "1000개 테스트" << std::endl;
	Span sp2 = Span(1000);
	srand(time(NULL));
	for (int idx = 0; idx < 1000; idx++) {
		sp2.addNumber(rand());
	}
	printVector(sp2.getVec());
	std::cout << "min : " << sp2.shortestSpan() << std::endl;
	std::cout << "max : " << sp2.longestSpan() << std::endl;

	return 0;
}