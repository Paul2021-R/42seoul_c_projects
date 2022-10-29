/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:28:55 by haryu             #+#    #+#             */
/*   Updated: 2022/10/29 21:18:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void) {
	Array<int> myArr(5);

	for (int i = 0; i < 5; i++)
		myArr.array[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << myArr.array[i] << std::endl;
	std::cout << "myArr size : " << myArr.size() << std::endl;

	Array<int> copyTest(myArr);
	for (int i = 0; i < 5; i++)
		std::cout << copyTest.array[i] << std::endl;

	Array<float> myArrB(5);

	for (int i = 0; i < 5; i++)
		myArrB.array[i] = i + 0.5;
	for (int i = 0; i < 5; i++)
		std::cout << myArrB.array[i] << std::endl;
	std::cout << "myArrB size : " << myArr.size() << std::endl;

	// Size over error
	try{
		Array<int> myArr2(1);
		std::cout << "error : " << myArr2[6] << std::endl;
	}
	catch (const char *str)
	{
		std::cerr << str << std::endl;
	}
	return (0);
}