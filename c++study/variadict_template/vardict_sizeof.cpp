// sizeof... 
// 원소들의 평균 구하기

#include <iostream>

// C++11 형식의 재귀 호출 종료 함수
// int sum_all() { return 0; }
// template <typename... Ints>
// int sum_all(int num, Ints... nums) {
// 	return num + sum_all(nums...);
//}

//C++ 17 형식 
template <typename... Ints>
int sum_all(Ints... nums) {
	return (... + nums); // Fold 형식 
	// 컴파일러는 이를 이렇게 해석한다. 
	// return ((((1 + 4) + 2) + 3) + 10);s
}

template <typename... Ints>
double average(Ints... nums) {
	std::cout << "sizeof... : " << sizeof...(nums) << std::endl;
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int main(void) {
	// 1, 4, 2, 3, 10
	std::cout << average(1, 4, 2, 3, 10) << std::endl;
}