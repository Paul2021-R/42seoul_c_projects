#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << *itr << std::endl;
	}
}

int main(void){
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	std::cout << "------------------------------------" << std::endl;

	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	std::cout << "------------------------------------" << std::endl;
	vec.erase(vec.begin() + 3);
	print_vector(vec);
	return 0;
}
