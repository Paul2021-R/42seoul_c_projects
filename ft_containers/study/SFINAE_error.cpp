#include <iostream>

template <typename T>
void test(typename T::x a) {
	// typename T::y b;
	std::cout << "T::x : " << a << std::endl;
}

template <typename T>
void test(typename T::y b) {
	std::cout << "T::y : " << b << std::endl;
}

struct A {
	using x = int;
};

int main() {
	test<A>(11);
}