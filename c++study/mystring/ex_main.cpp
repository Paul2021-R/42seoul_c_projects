#include "mystring.hpp"
#include <string>

int main(void) {
	// MyString str1("hello world!");
	// MyString str2(str1);

	// str1.printnl();
	// str2.printnl();

	// std::cout << str1.length() << std::endl;

	// char target[100];
	// std::cin.getline(target, 100);
	// MyString str3(target);
	// str3.printnl();
	// std::cout << str3.length() << std::endl;

// 	MyString str4("very very very long string jhdjdjf;asjfdajsklfj wqer;kl test test test ets test");
// 	str4.reserve(30);

// 	std::cout << "before Capacity : " << str4.capacity() << std::endl;
// 	std::cout << "before String length : " << str4.length() << std::endl;
// 	str4.printnl();

// 	MyString str5("test");
// 	std::cout << "before Capacity : " << str5.capacity() << std::endl;
// 	std::cout << "before String length : " << str5.length() << std::endl;
// 	str5.printnl();

// 	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;

// 	str4.insert(5, str5);
// 	str4.printnl();
// 	std::cout << "after Capacity : " << str4.capacity() << std::endl;
// 	std::cout << "after String length : " << str4.length() << std::endl;

// 	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;

// 	str4.erase(28, 5);
// 	std::cout << "erase 28, 5" << std::endl;
// 	str4.printnl();
// 	std::cout << "after Capacity : " << str4.capacity() << std::endl;
// 	std::cout << "after String length : " << str4.length() << std::endl;

// 	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;

// 	std::cout << str4.find(6, "test") << std::endl;
// 	std::cout << str4.at(65) << std::endl;
// 	std::cout << str4.at(66) << std::endl;
// 	std::cout << str4.at(67) << std::endl;
// 	std::cout << str4.at(68) << std::endl;
// }
  MyString str1("this is a very very long string");
  std::cout << "Location of first <very> in the string : " << str1.find(0, "very")
       << std::endl;
  std::cout << "Location of second <very> in the string : "
       << str1.find(str1.find(0, "very") + 1, "very") << std::endl;
}