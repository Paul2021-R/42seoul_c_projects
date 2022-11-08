#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
	Vector(size_t size): size_(size) {
		data_ = new T[size_];
		for (int i = 0; i < size; i++)
			data_[i] = 3;
	}
	const T& at(size_t index) const {
		if (index >= size_) {
			throw std::out_of_range("Vector 의 index 가 범위를 초과했습니다.");
		}
		return (data_[index]);
	}
	~Vector() { delete[] data_; }
private:
	T* data_;
	size_t size_;
};

int main(void) { 
	Vector<int> vec(3);

	int index, data = 0;
	std::cin >> index;

	try {
		data = vec.at(index);
	} catch (std::out_of_range& e) {
		std::cout << "예외 발생! " << e.what() << std::endl;
	}
	// 예외 발생하지 않았다면 3을 출력하고, 예외가 발생하면 원래의 data에 들어가있던 0이 출력된다. 
	std::cout << "읽은 데이터 : " << data << std::endl;
}