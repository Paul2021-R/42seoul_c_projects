#include <iostream>
#include <string>

class Base {
private:
	std::string s;

public: 
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl; 
	}
	void what(void) {
		std::cout << s << std::endl;
	}
};

class Derived : public Base {
private : 
	std::string s;

public : 
	Derived() : Base(), s("파생") {
		std::cout << "파생 클래스" << std::endl;
		what();
	}
	void what() { std::cout << s << std::endl; }
};

int main(void) {
	std::cout << " === 기반 클래스 생성 === " << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 === " << std::endl;
	Derived c;

	return (0);
}
