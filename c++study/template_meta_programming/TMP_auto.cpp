#include <iostream>
#include <typeinfo>

int sum(int a, int b) { return a + b; }

class SomeClass {
	int data;
public: 
	SomeClass(int d): data(d) {}
	SomeClass(const SomeClass& s): data(s.data){}
};

int main() {
	auto c = sum(1, 2); // 함수 리턴 타입으로 int를 추론
	auto num  = 1.0 + 2.0; // double 로 추측 가능

	SomeClass some(10);
	auto some2 = some;

	auto some3(10); // 이 경우 정상적으로 추론이 가능할까?

	std::cout << "c의 타입은? :: " << typeid(c).name() << std::endl;
	std::cout << "num의 타입은? :: " << typeid(num).name() << std::endl;
	std::cout << "some2의 타입은? :: " << typeid(some2).name() << std::endl;
	std::cout << "some3의 타입은? :: " << typeid(some3).name() << std::endl;
}