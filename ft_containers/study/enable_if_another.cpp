#include <iostream>

template <typename T>
class Testvector {
template <class Iterator>
struct is_iterator {
	bool value = false;
};

public:
	// element 가 num 개 들어있는 vector 를 만든다.
	Testvector(size_t num, const T& element){
		std::cout << element << " 를 " << num << " 개 만들기" << std::endl;
	}

	// 반복자 start 부터 end 까지로부터 벡터를 생성한다. 
	template <typename Iterator, typename = std::enable_if<is_iterator<Iterator>::value>>
	Testvector(Iterator start, Iterator end) {
		std::cout << "반복자를 이용한 생성자 호출" << std::endl;
	}
};


int main() { Testvector<int> v(10, 3); }