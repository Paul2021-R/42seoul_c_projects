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

// using one = INT<1>;
// using two = INT<2>;
// using three = INT<3>;

typedef INT<1> one;
typedef INT<2> two;
typedef INT<3> three;

template <typename N, typename d>
struct check_div {
	// result 중에서 한 개라도 true 면 전체가 true
	static const bool result = (N::num % d::num == 0) || check_div<N, typename add<d, one>::result>::result; 
};

template <typename N>
struct _is_prime {
	static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> {
	static const bool result = true;
};

template <>
struct _is_prime<three> {
	static const bool result = true;
};

template <typename N>
struct check_div<N, typename divide<N, two>::result> {
	static const bool result = (N::num % (N::num / 2) == 0);
};

template <int N>
struct is_prime {
	static const bool result = _is_prime< INT<N> >::result;
};

int main() {
  std::cout << std::boolalpha;
  std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl;   // true
  std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl;  // false

  std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl;  // true
  std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl;  // true
}