#include <iostream>

template <int X>
struct fib {
	static const int result = fib<X - 1>::result + fib<X - 2>::result;
};

template <>
struct fib<1> {
	static const int result = 1;
};

template <>
struct fib<0> {
	static const int result = 0;
};


int	main()	{
	std::cout << "5 번째 피보나치 수 :: " << fib<5>::result << std::endl; // 5
}