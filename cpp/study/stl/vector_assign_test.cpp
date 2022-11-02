#include <iostream>
#include <vector>

template<typename T>
void printVector(std::vector<T>& vec) {
	std::cout << "벡터 값 : [ ";
	int idx = 0;
	for(typename std::vector<T>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr) {
		std::cout << "(" << idx << ")번 : "<< *itr << " / ";
		idx++;
	}
	std::cout << " ]" << std::endl;
}

int main(void) {
	std::vector<int> vec1;
	std::vector<int> vec2;

	vec1.push_back(rand() % 10);
	vec1.push_back(rand() % 10);
	vec1.push_back(rand() % 10);
	vec1.push_back(rand() % 10);
	vec1.push_back(rand() % 10);
	vec1.push_back(rand() % 10);

	printVector(vec1);

	vec2.assign(vec1.begin(), vec1.end());
	printVector(vec2);
	
}