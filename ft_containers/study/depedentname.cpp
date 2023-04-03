#include <iostream>
#include <vector>

template<typename T>
void print_vector(std::vector<T>& vec) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << *itr << std::endl;
	}
}

int main() {
	std::vector<int> vec;
	int i = 0;
	vec.push_back(i += 10);
	vec.push_back(i += 10);
	vec.push_back(i += 10);
	vec.push_back(i += 10);

	std::cout << "벡터상태" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	print_vector(vec);
	std::cout << "-----------------------------" << std::endl;
	return 0;
}