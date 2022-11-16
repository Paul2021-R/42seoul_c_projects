#include <iostream>
#include <typeinfo>

template<int N>
struct Int {
	static const int num = N;
};

template <typename T, typename U>
struct add {
	typedef Int<T::num + U::num> result;
};

int main() {
	typedef Int<1> one;
	typedef Int<2> two;

	typedef add<one, two>::result three;

	std::cout << "Addtion result : " << three::num << std::endl;
}
