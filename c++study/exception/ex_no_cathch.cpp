#include <iostream>
#include <stdexcept>

int func() { throw std::runtime_error("error"); }

int main(void) {
	try {
		func();
	} catch (int i) {
		std::cout << "Catch int : " << i;
	}
}