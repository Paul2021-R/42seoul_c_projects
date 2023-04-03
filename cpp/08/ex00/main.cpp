/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:53:03 by haryu             #+#    #+#             */
/*   Updated: 2022/11/02 22:03:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

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

int main(void) {
	std::vector<int> test1;
	int value;
	srand(time(NULL));


	std::cout << "랜덤 값 0 ~ 9까지 입력" << std::endl;
	for (int idx = 0; idx < 10; idx++) {
		value = rand() % 10;
		test1.push_back(value);
	}
	printVector(test1);
	std::cout << "값 7의 위치는? : " << easyfind(test1, 7) << std::endl;
	std::cout << "값 11의 위치는? : " << easyfind(test1, 11) << std::endl;
}