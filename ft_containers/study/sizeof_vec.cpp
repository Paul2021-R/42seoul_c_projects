#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec (4, 8);
	std::cout << "vec 크기 : " << sizeof(vec) << std::endl;
	vec.push_back(1);
	std::cout << "vec 크기 : " << sizeof(vec) << std::endl;
	vec.push_back(1);
	std::cout << "vec 크기 : " << sizeof(vec) << std::endl;
	return (0);
}