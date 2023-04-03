#include <exception>
#include <iostream>

class Parent : public std::exception {
public:
    virtual const char* what(void) const _NOEXCEPT { return "Parent!\n"; }
};

class Child : public Parent {
public:
    const char* what() const _NOEXCEPT { return "Child\n"; }
};

int func(int c) {
    if (c == 1) {
        throw Parent();
    } else if (c == 2) {
        throw Child();
    }
    return 0;
}

int main(void) {
    int c;
    std::cin >> c;

    try {
        func(c);
    } catch (const Child & c) {
        std::cout << "Child Catch!" << std::endl;
        std::cout << c.what();
    } catch (const Parent & p) {
    	std::cout << "Parent Catch!" << std::endl;
        std::cout << p.what();
	}
}