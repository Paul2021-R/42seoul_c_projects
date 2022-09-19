/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystring.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:44:03 by haryu             #+#    #+#             */
/*   Updated: 2022/09/19 18:42:11 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <string>
#include <string.h>

class MyString 
{
private:
	char*		 	StringContent;
	size_t			StringSize;
	size_t			MemCapacity;

public:

	MyString(char c); // 문자 하나에서 생성
	MyString(const char *string); // 문자열에서 생성
	MyString(const MyString &str); //복사 생성자
	~MyString(void);
	

	MyString&		operator=(MyString &str);
	MyString&		assign(const MyString& str);
	MyString&		assign(const char* str);

	size_t			length(void) const ;
	void			print(void) const ;
	void			printnl(void) const ;
	size_t			capacity() {return MemCapacity;};
	void			reserve(size_t size);
	char			at(int i) const ;
};

MyString::MyString(const MyString &str){
	StringSize = str.StringSize;
	StringContent = new char[StringSize];
	MemCapacity = StringSize;
	for (int idx = 0; idx < StringSize; idx++)
		StringContent[idx] = str.StringContent[idx];
}

MyString::MyString(const char *string) {
	StringSize = strlen(string);
	StringContent = new char[StringSize];
	MemCapacity = StringSize;
	for (int idx = 0; idx < StringSize; idx++)
		StringContent[idx] = string[idx];
}

MyString::MyString(char c) : StringSize(1), MemCapacity(1) {
	StringContent = new char[1];
	StringContent[0] = c;
}

MyString::~MyString(void){
	delete[] StringContent;
}

MyString&	MyString::operator=(MyString &str){
	StringContent = (str.StringContent);
	StringSize = str.StringSize;
	MemCapacity = str.MemCapacity;
	return *this;
}

size_t		MyString::length(void) const {return StringSize;} // const 위치에 따라 다른 의미를 가지는 것으로 생각됨

void		MyString::print(void) const {
	std::cout << StringContent;
};
void		MyString::printnl(void) const {
	std::cout << StringContent << std::endl;
};

MyString&	MyString::assign(const MyString& str) {
	if (str.StringSize > MemCapacity) {
		delete[] StringContent;

		StringContent = new char[str.StringSize];
		MemCapacity = str.StringSize;
	}
	for (int idx = 0; idx != str.StringSize; idx++) {
		StringContent[idx] = str.StringContent[idx];
	}
	StringSize = str.StringSize;
	return *this;
};

MyString&	MyString::assign(const char* str){
	size_t len = strlen(str);

	if (len > MemCapacity) {
		delete[] StringContent;

		StringContent = new char[len];
		MemCapacity = len;
	}
	for (int idx = 0; idx != len; idx++) {
		StringContent[idx] = str[idx];
	}
	StringSize = len;
	return *this;
};

void	MyString::reserve(size_t size) {
	if (size > MemCapacity) {
		char*	PrevString = StringContent;
		StringContent = new char(size);
		MemCapacity = size;
		for (int idx = 0; idx < size; idx++)
			StringContent[idx] = PrevString[idx];
		delete[] PrevString;
	}
	else
		return ;
}

char	MyString::at(int i) const {
	if (i >= StringSize || i < 0) {
		return NULL;
	}
	else
		return StringContent[i];
}

#endif