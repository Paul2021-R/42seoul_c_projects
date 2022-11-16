#include <iostream>

template <int N> 
struct INT {
	static const int num = N;
};

template <typename a, typename b>
struct add {
	typedef INT <a::num + b::num> result;
};

template <typename a, typename b>
struct divide {
	typedef INT<a::num / b::num> result;
};

typedef INT<1> = one;
typedef INT<2> = two;
typedef INT<3> = three;

template <>
struct is_prime<2> {
	static const bool result = true;
};

template <>
struct is_prime<3> {
	static const bool result = true;
};

template <int N>
struct is_prime {
	static const bool result = !check_div<N, 2>::result;
};

template <int N, int d>
struct check_div {
	static const bool result = (N % d) || check_div<N, d + 1>:: result; 
};

template <int N>
struct check_div<N, N / 2> {
	static const bool result = (N % (N / 2) == 0);
};

int main() {
  std::cout << std::boolalpha;
  std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl;   // true
  std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl;  // false

  std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl;  // true
  std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl;  // true
}