#include <iostream>
#include <string>
#include <type_traits>

template <typename T, typename = std::enable_if<std::is_integral<decltype(std::declval<T>().func())>::value>>
void test(const T& t) {
	std::cout << "t.fuc() : " << t.func() << std::endl;
}

struct A {
	int func() const { return 1; }
};

struct B {
	int func() const { return 'a'; }
};

struct C {
	std::string func() const { return "hello world"; }
};

int main() { 
	test(A{});
	test(B{});
	test(C{});
}