#include <iostream>

template <typename T>
void test(typename T::x a) {
	std::cout << "T::x : " << a << std::endl;
}

template <typename T>
void test(typename T::y b) {
	std::cout << "T::y : " << b << std::endl;
}

struct A {
	using x = int;
};

struct B {
	using y = int;
};

int main() {
	test<A>(33);
	test<B>(22);
}