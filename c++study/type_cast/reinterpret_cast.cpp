#include <iostream>

int main(void) {
	int num = 0x140204;
	char* ptr = reinterpret_cast<char*>(&num);
	std::cout << static_cast<int>(*(ptr+0)) << std::endl; 
	std::cout << static_cast<int>(*(ptr+1)) << std::endl; 
	std::cout << static_cast<int>(*(ptr+2)) << std::endl; 
	std::cout << static_cast<int>(*(ptr+3)) << std::endl; 
	if (ptr[0] == '\x04')
		std::cout << "little-endian" << std::endl;
	else
		std::cout << "big-endian" << std::endl;
}