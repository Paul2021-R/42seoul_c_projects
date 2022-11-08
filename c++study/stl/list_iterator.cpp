#include <iostream>
#include <list> 

template <typename T>
void print_list(std::list<T>& lst) {
	std::cout << "[ ";
	for (const auto& elem : lst) {
		std::cout << elem << " ";
	}
	std::cout << " ]" << std::endl;
}

int main(void) {
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	std::cout << "처음 리스트의 상태" << std::endl;
	print_list(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == 20) {
			lst.insert(itr, 50);
		}
	}

	std::cout << "값이 20인 원소 앞에 50을 추가" << std::endl;
	print_list(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == 30) {
			lst.erase(itr);
			break ;
		}
	}
	std::cout << "값이 30인 원소를 제거한다." << std::endl;
	print_list(lst);
}
