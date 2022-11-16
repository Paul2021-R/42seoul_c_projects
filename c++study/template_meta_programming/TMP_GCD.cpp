// TMP GCD 구하기 예제
#include <iostream>

template<int X, int Y>
struct GCD{
	static const int value = GCD<Y, X % Y>::value;
	};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

int main() {
	std::cout << "gcd (36, 24) :: " << GCD<36, 24>::value << std::endl;
}