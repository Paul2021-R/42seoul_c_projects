#include "mystring.hpp"
#include <string>

int main(void) {
	MyString str1("hello world!");
	MyString str2(str1);

	str1.printnl();
	str2.printnl();

	std::cout << str1.length() << std::endl;

	char target[100];
	std::cin.getline(target, 100);
	MyString str3(target);
	str3.printnl();
	std::cout << str3.length() << std::endl;

	MyString str4("very very very long string");
	str4.reserve(30);

	std::cout << "Capacity : " << str4.capacity() << std::endl;
	std::cout << "String length : " << str4.length() << std::endl;
	str4.printnl();
}