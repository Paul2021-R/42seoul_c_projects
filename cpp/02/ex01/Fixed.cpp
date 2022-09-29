#include "Fixed.hpp"

Fixed::Fixed(void): 
	FixedPointVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	FixedPointVal = num << fractionalBit; 
}
// 정수 값이기에, 고정 소수점 부분에서, 소수점이 아닌 영역으로 정수를 밀어주면 된다. 

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	FixedPointVal = roundf(num * (1 << fractionalBit));
}
// round 함수의 실수만 받아서, 소수를 날리고 정수로 만들어준다. 즉, 2^8 으로 만든 비트를 num 에 곱해지면, 자리값이 8칸 상승하게 된다. 
// 그렇게 만든 값에 float으로 강제 형변환된 상태에서 소수를 반올림으로 날린다. 
// 이렇게 하면 보다 정확한 고정 소수점 값을 얻게 된다. 

Fixed::Fixed(const Fixed& target){
	std::cout << "Copy constructor called" << std::endl;
	*this = target;
}

Fixed& Fixed::operator=(const Fixed& target) {
	std::cout << "Copy assignment operator called" << std::endl;
	FixedPointVal = target.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (FixedPointVal);
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits memeber function called" << std::endl;
	FixedPointVal = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)getRawBits() / (float)(1 << fractionalBit));
}// 정수로 저장된 값을 float 으로 만든 뒤에, 이를 다시 원래의 값으로 바꾸어야 하므로, 소수점 비트만큼을 잡아 당겨 비트 이동을 해야 한다. 

int		Fixed::toInt(void) const{
	return (getRawBits() >> fractionalBit);
}
// 소수부가 없으므로 그냥 비트 이동으로 충분하다. 

std::ostream& operator<<(std::ostream&s, const Fixed& target) {
	
	std::cout << target.toFloat();
	return s;
}
// 연산자의 오버로딩은 friend 키워드를 사용하지 않는 이상, 멤버변수로 어떤 특정 객체 내에 만들어 사용이 불가능하다. 
// 오히려 밖에 정의해야 한다. 
