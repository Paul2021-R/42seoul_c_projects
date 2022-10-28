/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:34:13 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 17:50:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef unsigned long int uintptr_t; //8 바이트 부호 없이 사용 하기 위해 지정
// 미지정시 <cstdint> 라이브러리를 써야 하는데, 이는 C++11 기반임

typedef struct s_Data {
	int	data;
}			Data;

uintptr_t	serialize(Data * ptr);
Data*		desirialze(uintptr_t raw);
// 리눅스 시스템에서 어째선지 컴파일러가 인식을 이상하게 함 = =;;

uintptr_t	serialize(Data * ptr) {
	uintptr_t	addressVal;

	addressVal = reinterpret_cast<uintptr_t>(ptr);
	return (addressVal);
}

Data*	deserialize(uintptr_t raw) {
	Data*	addressVal;
	// 핵심은 포인터, 참조 관련된 강제적 형변환을 지원하는 해당 재해석 캐스팅을 사용한다는 점이다. 
	// 기존의 정적, 동적 캐스팅으로 불가능한 포인터 조작의 입출구 역할을 맡아서 하게 된다. 
	addressVal = reinterpret_cast<Data *>(raw);
	return (addressVal);
}

int main(void) {
	Data *			structure = new Data();
	uintptr_t		addressData;
	Data *			anotherPtr;


	structure->data = 1010;
	std::cout << structure->data << std::endl;
	addressData = serialize(structure);
	std::cout << "original Data Pointer : " << structure << std::endl;
	std::cout << "original Data Pointer(data) : " << structure->data << std::endl;
	// std::hex로 16진수 변환하여 살펴보면, 동일한 주소값이 들어가 있음을 볼 수 있다. 
	std::cout << "uintptr_t raw data : " << std::hex << addressData << std::endl;
	anotherPtr = deserialize(addressData);
	std::cout << "deserialized Data Pointer : " << anotherPtr << std::endl;
	std::cout << "deserialized Data Pointer(data) : " << std::dec << anotherPtr->data << std::endl;
	delete structure;
}