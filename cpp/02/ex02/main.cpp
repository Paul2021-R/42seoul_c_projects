#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed c(16.4f);
	Fixed d(20.2f);

	if ((c < d) == true)
		std::cout << "c < d 는 참입니다." << std::endl;
	else
		std::cout << "c < d 는 거짓입니다." << std::endl;

	return 0;
}
