/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:57:23 by haryu             #+#    #+#             */
/*   Updated: 2022/10/04 15:57:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): 
	FixedPointVal(0) {
}

Fixed::Fixed(const int num) {
	FixedPointVal = num << fractionalBit; 
}
// 정수 값이기에, 고정 소수점 부분에서, 소수점이 아닌 영역으로 정수를 밀어주면 된다. 

Fixed::Fixed(const float num) {
	FixedPointVal = roundf(num * (1 << fractionalBit));
}
// round 함수의 실수만 받아서, 소수를 날리고 정수로 만들어준다. 즉, 2^8 으로 만든 비트를 num 에 곱해지면, 자리값이 8칸 상승하게 된다. 
// 그렇게 만든 값에 float으로 강제 형변환된 상태에서 소수를 반올림으로 날린다. 
// 이렇게 하면 보다 정확한 고정 소수점 값을 얻게 된다. 

Fixed::Fixed(const Fixed& target){
	*this = target;
}

/////////////////////////////////////////////////////////////////////
/* operator */
/**
 * @brief 사칙연산을 구현, 값을 float으로 변환한 뒤 진행을 한다. 
 * 
 * @param val 연산 대상
 * @return Fixed 해당 내용은 기존의 값까지 바꾸는 레퍼런스 타입으로 반환하면 연산의 오류가 발생하므로, 또 다른 객채를 반환 붙여넣는 방식으로 구현됨.
 */
Fixed	Fixed::operator+(const Fixed& val) {
	return (Fixed(this->toFloat() + val.toFloat()));
}

/**
 * @brief 사칙연산을 구현, 값을 float으로 변환한 뒤 진행을 한다. 
 * 
 * @param val 연산 대상
 * @return Fixed 해당 내용은 기존의 값까지 바꾸는 레퍼런스 타입으로 반환하면 연산의 오류가 발생하므로, 또 다른 객채를 반환 붙여넣는 방식으로 구현됨.
 */
Fixed	Fixed::operator-(const Fixed& val) {
	return (Fixed(this->toFloat() - val.toFloat()));
}

/**
 * @brief 사칙연산을 구현, 값을 float으로 변환한 뒤 진행을 한다. 
 * 
 * @param val 연산 대상
 * @return Fixed 해당 내용은 기존의 값까지 바꾸는 레퍼런스 타입으로 반환하면 연산의 오류가 발생하므로, 또 다른 객채를 반환 붙여넣는 방식으로 구현됨.
 */
Fixed	Fixed::operator*(const Fixed& val) {
	return (Fixed(this->toFloat() * val.toFloat()));
}

/**
 * @brief 사칙연산을 구현, 값을 float으로 변환한 뒤 진행을 한다. 
 * 
 * @param val 연산 대상
 * @return Fixed 해당 내용은 기존의 값까지 바꾸는 레퍼런스 타입으로 반환하면 연산의 오류가 발생하므로, 또 다른 객채를 반환 붙여넣는 방식으로 구현됨.
 */
Fixed	Fixed::operator/(const Fixed& val) {
	return (Fixed(this->toFloat() / val.toFloat()));
}

/**
 * @brief 비교 연산자 오버로딩, 그냥 비트값 그대로 구현하여도 상관 없다. 
 * 
 * @param val 비교대상
 * @return true 
 * @return false 
 */
bool	Fixed::operator<(const Fixed& val) const {
	return (this->FixedPointVal < val.FixedPointVal);
}

/**
 * @brief 비교 연산자 오버로딩, 그냥 비트값 그대로 구현하여도 상관 없다. 
 * 
 * @param val 비교대상
 * @return true 
 * @return false 
 */
bool	Fixed::operator>(const Fixed& val) const {
	return (this->FixedPointVal > val.FixedPointVal);
}

/**
 * @brief 비교 연산자 오버로딩, 그냥 비트값 그대로 구현하여도 상관 없다. 
 * 
 * @param val 비교대상
 * @return true 
 * @return false 
 */
bool	Fixed::operator<=(const Fixed& val) const {
	return (this->FixedPointVal <= val.FixedPointVal);
}

/**
 * @brief 비교 연산자 오버로딩, 그냥 비트값 그대로 구현하여도 상관 없다. 
 * 
 * @param val 비교대상
 * @return true 
 * @return false 
 */
bool	Fixed::operator>=(const Fixed& val) const {
	return (this->FixedPointVal >= val.FixedPointVal);
}

/**
 * @brief 비교 연산자 오버로딩, 그냥 비트값 그대로 구현하여도 상관 없다. 
 * 
 * @param val 비교대상
 * @return true 
 * @return false 
 */
bool	Fixed::operator==(const Fixed& val) const {
	return (this->FixedPointVal == val.FixedPointVal);
}

/**
 * @brief 비교 연산자 오버로딩, 그냥 비트값 그대로 구현하여도 상관 없다. 
 * 
 * @param val 비교대상
 * @return true 
 * @return false 
 */
bool	Fixed::operator!=(const Fixed& val) const {
	return (this->FixedPointVal != val.FixedPointVal);
}

/**
 * @brief 전위 증가 연산자
 * 
 * @return Fixed& 해당 연산자는 호출한 쪽에서 값이 수정되어서, 수정된 값을 다음 명령에 바로 대입한다. 따라서 반환 값은 기존 값을 수정할 수 있는 레퍼런스 타입으로 반환된다.
 */
Fixed& Fixed::operator++(void) {
	this->FixedPointVal++;
	return (*this);
}

/**
 * @brief 후위 증가 연산자
 * 
 * @return Fixed 후위 증가 연산자는 기준이 되는 인자가 들어온 것으로 인지한다. 또한 호출 된 당시에는 당장 사용되는 것이 아닌, 반복문을 돌아서 다시 오는 경우 등에 값이 갱신된 형태이므로, 레퍼런스 반환타입을 가지지 않는다. 
 */
Fixed Fixed::operator++(int) {
	Fixed	temp(*this);

	this->FixedPointVal++;
	return (temp);
}

/**
 * @brief 전위 감소 연산자
 * 
 * @return Fixed& 증가 연산자 설명 참고
 */
Fixed& Fixed::operator--(void) {
	this->FixedPointVal--;
	return (*this);
}

/**
 * @brief 후위 감소 연산자
 * 
 * @return Fixed 후위 연산자 설명 참고
 */
Fixed Fixed::operator--(int) {
	Fixed	temp(*this);

	this->FixedPointVal--;
	return (temp);
}

/**
 * @brief 해당 연산자는 대상을 대입하여 새로운 공간에 넣어주는 역할을 한다. 따라서 얕은 복사가 아닌 값을 새로이 할당해주는 방식으로 깊은 복사가 일어나야 한다. 따라서 기존의 객체에 인자인 객체의 값을 출력하여, 이를 대상 객체에 적용한다. 
 * 
 * @param target 
 * @return Fixed& 
 */
Fixed& Fixed::operator=(const Fixed& target) {
	FixedPointVal = target.getRawBits();
	return *this;
}

/////////////////////////////////////////////////////////////////////
/* static 함수 케이스 */
// 객체 없이 클래스 자체가 관리하며, 클래스에서 바로 호출이 가능한 함수들은 static이라는 예약어로 표시한다.
// const 키워드가 있는 변수를 취하는 경우 값이 함수 내부에서 변경되지 않는 다는 것인 만큼, 값이 변할 염려를 하지 않아도 되서 안정적이다. 

Fixed& Fixed::min(Fixed& valA, Fixed& valB) {
	if (valA < valB)
		return (valA);
	return (valB);
}

Fixed const & Fixed::min(const Fixed& valA, const Fixed& valB) {
	if (valA < valB)
		return (valA);
	return (valB);
}

Fixed& Fixed::max(Fixed& valA, Fixed& valB) {
	if (valA > valB)
		return (valA);
	return (valB);
}

Fixed const & Fixed::max(const Fixed& valA, const Fixed& valB) {
	if (valA > valB)
		return (valA);
	return (valB);
}

/////////////////////////////////////////////////////////////////////
Fixed::~Fixed() {}

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

/**
 * @brief string 클래스 표준 출력 연산자 오버로딩 함수. friend 키워드를 사용해야만 함수의 클래스나 접근 제어 지시자의 영향을 받지 않을 수 있다. 
 * 
 * @param s 값을 넣을 스트립 레퍼런스
 * @param target 대상이 되는 숫자 값 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream&s, const Fixed& target) {
	
	std::cout << target.toFloat();
	return s;
}

