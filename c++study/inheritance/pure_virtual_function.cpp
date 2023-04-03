#include <iostream>

class Animal {
public:
	Animal() {}
	virtual ~Animal() {}
	virtual void speak() = 0;
};

class Dog : public Animal {
public:
	Dog(): Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main(void) {
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
}
