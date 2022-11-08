/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystring.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:44:03 by haryu             #+#    #+#             */
/*   Updated: 2022/09/21 17:57:10 by haryu            ###   ########.fr       */
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

	MyString&		insert(int loc, const MyString& str);
	MyString&		insert(int loc, const char* str);
	MyString&		insert(int loc, char c);

	MyString&		erase(int loc, int num);

	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;

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
	StringSize = 0;
	MemCapacity = 0;
	std::cout << "Delete finished" << std::endl;
}

MyString&	MyString::operator=(MyString &str){
	StringContent = (str.StringContent);
	StringSize = str.StringSize;
	MemCapacity = str.MemCapacity;
	return *this;
}

size_t		MyString::length(void) const {return StringSize;} // const 위치에 따라 다른 의미를 가지는 것으로 생각됨

void		MyString::print(void) const {
	for (int idx = 0; idx < StringSize; idx++) {
		std::cout << StringContent[idx];
	}
};
void		MyString::printnl(void) const {
	print();
	std::cout << std::endl;
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
		StringContent = new char[size]; 
		// 새로운 할당 시 () 안에 할당하면 컴파일도 되고 이상없는데 놀랍게도 ㅁ메모리 오버랩이 일어남
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
		return '\0';
	}
	else
		return StringContent[i];
}

MyString&	MyString::insert(int loc, const MyString& str) {
	if (loc < 0 || loc > StringSize) return *this;

	char	*temp;
	int		i = 0;
	size_t	LengSum = StringSize + str.StringSize;

	if (LengSum <= MemCapacity) {
		for (int idx = StringSize + str.StringSize; idx >= loc + str.StringSize; idx--) {
			StringContent[idx] = StringContent[StringSize - i];
			i++;
		}
		StringSize = LengSum;
		i = 0;
		for (; i < str.StringSize; i++) {
			StringContent[i + loc] = str.StringContent[i];
		}
		// temp = new char[StringSize - loc];
		// for (int idx = loc; idx <= StringSize; idx++) {
		// 	temp[i] = StringContent[idx];
		// 	i++;
		// }
		// i = 0;
		// for (int idx = loc; idx - loc < str.StringSize; idx++) {
		// 	StringContent[idx] = str.StringContent[i];
		// 	i++;
		// }
		// i = 0;
		// for (int idx = str.StringSize + loc; idx < LengSum; idx++) {
		// 	StringContent[idx] = temp[i];
		// 	i++;
		// }
		if ((int)MemCapacity - (int)(StringSize * 2) < 0)
			reserve(MemCapacity * 2);
	}
	else {
		temp = new char[LengSum];
		for (int idx = 0; idx < loc; idx++) {
			temp[idx] = StringContent[idx];
		}
		for (int idx = loc; idx - loc < str.StringSize; idx++) {
			temp[idx] = str.StringContent[i];
			i++;
		}
		i = loc;
		for (int idx = str.StringSize + loc; idx < LengSum; idx++) {
			temp[idx] = StringContent[i];
			i++;
		}
		reserve(MemCapacity * 2);
		assign(temp);
		delete[] temp;
	}
	return *this;
}

MyString&	MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}

MyString&	MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString&	MyString::erase(int loc, int num) {
	if (loc < 0 || num < 0 || loc > StringSize) return *this;

	int left = num + loc;

	for (int idx = left; idx < StringSize; idx++) {
		StringContent[idx - num] = StringContent[idx];
	}
	if (left < StringSize) StringSize -= num;
	else {StringSize -= num - (left - StringSize);}

	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	if (find_from > StringSize || find_from < 0 || str.StringSize < 0) return -1;

	int i; 
	int	j = str.StringSize - 1;
	int prevPos = -1;

	for (i = StringSize - 1; i >= find_from; i--) {
		if (StringContent[i] == str.StringContent[j]) {
			int k = i - j;
			if (k < 0)
				return prevPos;
			for (int idx = 0; idx < str.StringSize; idx++) {
				if (k < find_from) return prevPos;
				if (StringContent[k++] == str.StringContent[idx]) continue;
				else break;
			}
			if (k - (i - j) == str.StringSize) 
				prevPos = i - j;
			else 
				i -= j;

		}
		if (i < str.StringSize)
			break ;
	}
	return prevPos;
}

int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return (find(find_from, temp));
}
int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return (find(find_from, temp));
}

int MyString::compare(const MyString& str) const {
	for (int idx = 0; idx < std::min(StringSize, str.StringSize); i++) {
		if (StringContent[i] > str.StringContent[i])
			return 1;
		else if (StringContent[i] < str.StringContent[i])
			return -1;
	}
	if (StringSize == str.StringSize) return 0;
	else if (StringSize > str.StringSize) return 1;
	else return -1;
}

#endif