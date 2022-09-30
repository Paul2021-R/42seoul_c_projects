#include <iostream>

class A {
	mutable int data_;

public:
	A(int data) : data_(data) {}
	void DoSomething (int x) const {
		data_ = x; // 불가능한 조장
	}
		void PrintData() const { std::cout << "data : " << data_ << std::endl; }
};

int main() {
	A a(10);
	a.DoSomething(3);
	a.PrintData();
}
